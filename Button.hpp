#pragma once
#include "UI.hpp"
#include "raylib.h"
#include "TextureCreator.hpp"
#include "TextField.hpp"

class Button : public UI{
public:
    Button(TextureCreator& generatedObj, float spawnPosX, float spawnPosY);
    bool CheckCollision();
private:
    void Display() override;   
    float _spawnPosX, _spawnPosY;
    TextureCreator& _generatedObj;     
    static constexpr int buttonSize = 40; // width and height value of the button
};