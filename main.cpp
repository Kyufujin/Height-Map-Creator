#include "raylib.h"
#include "TextureCreator.hpp"
#include "UI.hpp"
#include "TextField.hpp"
#include "Button.hpp"
#include "ButtonGenerate.hpp"

#include <memory>

int main()
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Generated Height Map");
    Camera camera = { { 18.0f, 26.0f, 18.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    TextureCreator creator(32, 0, 0);   
    creator.saveGeneratedMap();

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

                DrawModel(creator.generatedModel, creator.generatedMapPosition, 1.0f, DARKGREEN);

                DrawGrid(20, 1.0f);

            EndMode3D();

            DrawTexture(creator.generatedTexture, screenWidth - creator.generatedTexture.width - 20, 20, WHITE);
            DrawRectangleLines(screenWidth - creator.generatedTexture.width - 20, 20, creator.generatedTexture.width, creator.generatedTexture.height, GREEN);
            DrawText("Use mouse scroll to change the view", screenWidth - 190, 160, 3, GREEN);
                       
            // ui starts here
            std::shared_ptr<UI> frequencyField = std::make_shared<TextField>("Frequency", std::to_string(creator.frequency), 60, 20);
            std::shared_ptr<UI> forceField = std::make_shared<TextField>("Force", std::to_string(creator.force), 60, 70);
            std::shared_ptr<UI> flatField = std::make_shared<TextField>("Flat", std::to_string(creator.flat), 60, 120);
            
            frequencyField->Display();
            forceField->Display();
            flatField->Display();

            frequencyField = std::make_shared<Button>(creator,"Frequency",10,10);
            forceField = std::make_shared<Button>(creator,"Force",10,60);
            flatField = std::make_shared<Button>(creator,"Flat",10,110);
            
            frequencyField->Display();
            forceField->Display();
            flatField->Display();

            std::shared_ptr<UI> generateButton = std::make_shared<ButtonGenerate>(creator,10, 160);
            generateButton->Display();           
  
        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(creator.generatedTexture);     // Unload texture
    UnloadModel(creator.generatedModel);         // Unload model

    CloseWindow();              // Close window and OpenGL context

    return 0;
}