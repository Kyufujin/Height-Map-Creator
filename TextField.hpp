#pragma once
#include "UI.hpp"
#include "raylib.h"
#include <string>



class TextField : public UI{
public:
    TextField(std::string textToDisplay, std::string paramToDisplay, int spawnPosX, int spawnPosY);
    void Display() override;
    int fontSize = 3; //default
private:
    std::string _textToDisplay;
    std::string _paramToDisplay;
    int _spawnPosX, _spawnPosY;
    std::string getParamAsText(std::string textToDisplay, std::string paramToDisplay);
};