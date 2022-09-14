#include "Button.hpp"

Button::Button(float spawnPosX, float spawnPosY) :  _spawnPosX(spawnPosX),
                                                    _spawnPosY(spawnPosY)
{}

void Button::Display(){
    Rectangle buttonRecMinus{_spawnPosX, _spawnPosY, buttonSize, buttonSize};
    Rectangle buttonRecPlus{_spawnPosX + 110, _spawnPosY, buttonSize, buttonSize};

    // buttons fields
    DrawRectangleRec(buttonRecMinus, RED);
    DrawRectangleRec(buttonRecPlus, GREEN);

    if(CheckCollisionPointRec(GetMousePosition(),buttonRecMinus)){
        DrawRectangleLines(_spawnPosX, _spawnPosY, buttonSize, buttonSize, GREEN);
            CheckCollision();
    } 
    else if(CheckCollisionPointRec(GetMousePosition(),buttonRecPlus)){
        DrawRectangleLines(_spawnPosX + 110, _spawnPosY, buttonSize, buttonSize, RED);
            CheckCollision();
    } 
}

bool Button::CheckCollision(){
    bool state = false;
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        state = true;       
    }
    return state;
}