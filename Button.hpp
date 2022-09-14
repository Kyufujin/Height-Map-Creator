#pragma once
#include "UI.hpp"
#include "raylib.h"

class Button : public UI{
public:
    Button(float spawnPosX, float spawnPosY);
private:
    void Display() override;
    bool CheckCollision();
    float _spawnPosX, _spawnPosY;     
    static constexpr int buttonSize = 40; // width and height value of the button
};