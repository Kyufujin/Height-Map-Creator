#include "ButtonGenerate.hpp"

ButtonGenerate::ButtonGenerate(TextureCreator& generatedObj,float spawnPosX, float spawnPosY) : _generatedObj(generatedObj),  
                                                                                                _spawnPosX(spawnPosX),
                                                                                                _spawnPosY(spawnPosY)
{}

void ButtonGenerate::Display(){
    Rectangle buttonGenerate{_spawnPosX, _spawnPosY, buttonSize + 110, buttonSize};
    DrawRectangleRec(buttonGenerate, BLUE);
    DrawText("Create HeightMap!",35,175, 5, WHITE);

    if(CheckCollisionPointRec(GetMousePosition(),buttonGenerate)){
        DrawRectangleLines(_spawnPosX, _spawnPosY, buttonSize + 110, buttonSize, GREEN);
            if(CheckCollision()){
                _generatedObj.eraseData();
                _generatedObj.defineBaseConfig();              
            }
    } 
}

bool ButtonGenerate::CheckCollision(){
    bool state = false;
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        state = true;     
    }
    return state;
}