#include "raylib.h"
#include "TextureCreator.hpp"

int main()
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Generated Height Map");

    // Define custom camera
    Camera camera = { { 18.0f, 26.0f, 18.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    TextureCreator creator(32, 0, 0);   
    creator.saveGeneratedMap();

    //Image image = LoadImage("../heightmap.png");             // Load heightmap image (RAM), for now lets use some random heightmap
    Texture2D texture = LoadTextureFromImage(creator.getGeneratedImage());                // Convert image to texture (VRAM)

    Mesh mesh = GenMeshHeightmap(creator.getGeneratedImage(), (Vector3){ 16, 6, 16 });    // Generate heightmap mesh (RAM and VRAM)
    Model model = LoadModelFromMesh(mesh);                          // Load model from generated mesh

    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;// Set map diffuse texture
    Vector3 mapPosition = { -8.0f, 0.0f, -8.0f };                   // Define model position

    UnloadImage(creator.getGeneratedImage());                     // Unload heightmap image from RAM, already uploaded to VRAM

    SetCameraMode(camera, CAMERA_ORBITAL);  // Set an orbital camera mode

    SetTargetFPS(60);                       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------    

    bool drawRoundedLines = false;
    // Main loop of the app
    while (!WindowShouldClose())            // Detect window close button or ESC key
    {
        // Update
        UpdateCamera(&camera);        

        // Draw       
        BeginDrawing();

            ClearBackground(BLACK);

            BeginMode3D(camera);

                DrawModel(model, mapPosition, 1.0f, DARKGREEN);

                DrawGrid(20, 1.0f);

            EndMode3D();

            DrawTexture(texture, screenWidth - texture.width - 20, 20, WHITE);
            DrawRectangleLines(screenWidth - texture.width - 20, 20, texture.width, texture.height, GREEN);
            DrawText("Use mouse scroll to change the view", screenWidth - 190, 160, 3, GREEN);             
        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(texture);     // Unload texture
    UnloadModel(model);         // Unload model

    CloseWindow();              // Close window and OpenGL context

    return 0;
}