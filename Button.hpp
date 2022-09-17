#pragma once
#include "UI.hpp"
#include "raylib.h"
#include "TextureCreator.hpp"
#include "TextField.hpp"

class Button : public UI{
public:
    Button(TextureCreator& generatedObj,std::string paramToModify, float spawnPosX, float spawnPosY);
    bool CheckCollision();
    void SetParamOnActionSubtract();
    void SetParamOnActionAdd();
private:
    void Display() override;
    std::string _paramToModify;   
    float _spawnPosX, _spawnPosY;
    TextureCreator& _generatedObj;     
    static constexpr int buttonSize = 40; // width and height value of the button
};