#include "Button.hpp"

Button::Button(TextureCreator& generatedObj,std::string paramToModify, float spawnPosX, float spawnPosY) : _generatedObj(generatedObj),
                                                                                                            _paramToModify(paramToModify),
                                                                                                            _spawnPosX(spawnPosX),
                                                                                                            _spawnPosY(spawnPosY)
{}

void Button::Display(){
    Rectangle buttonRecMinus{_spawnPosX, _spawnPosY, buttonSize, buttonSize};
    Rectangle buttonRecPlus{_spawnPosX + 110, _spawnPosY, buttonSize, buttonSize};

    // buttons fields
    DrawRectangleRec(buttonRecMinus, RED);
    DrawRectangleRec(buttonRecPlus, GREEN);
    std::string temp = "Flat";
    if(CheckCollisionPointRec(GetMousePosition(),buttonRecMinus)){
        DrawRectangleLines(_spawnPosX, _spawnPosY, buttonSize, buttonSize, GREEN);
            if(CheckCollision()){
                SetParamOnActionSubtract();               
            }
    } 
    else if(CheckCollisionPointRec(GetMousePosition(),buttonRecPlus)){
        DrawRectangleLines(_spawnPosX + 110, _spawnPosY, buttonSize, buttonSize, RED);
            if(CheckCollision()){
                SetParamOnActionAdd();
            }
    } 
}

bool Button::CheckCollision(){
    bool state = false;
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        state = true;     
    }
    return state;
}


void Button::SetParamOnActionSubtract(){
    switch(returnParameter(_paramToModify))
    {
        case CreatorParameters::Force : {
            // force action 
            _generatedObj.force-=1;
            break;
        }

        case CreatorParameters::Flat : {
            // flat action
            _generatedObj.flat-=1;
            break;
        }

        case CreatorParameters::Frequency : {
            // frequency action
            _generatedObj.frequency-=1;
            break;
        }

        default: {
            break;
        }
    }
}

void Button::SetParamOnActionAdd(){
    switch(returnParameter(_paramToModify))
    {
        case CreatorParameters::Force : {
            // force action 
            _generatedObj.force+=1;
            break;
        }

        case CreatorParameters::Flat : {
            // flat action
            _generatedObj.flat+=1;
            break;
        }

        case CreatorParameters::Frequency : {
            // frequency action
            _generatedObj.frequency+=1;
            break;
        }

        default: {
            break;
        }
    }
}

