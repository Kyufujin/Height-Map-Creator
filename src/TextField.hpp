#pragma once
#include "UI.hpp"
#include "raylib.h"
#include "TextureCreator.hpp"
#include <string>
#include <iomanip>

class TextField : public UI{
public:
    TextField(std::string textToDisplay, std::string paramToDisplay, int spawnPosX, int spawnPosY);
    void Display() override;
    static constexpr int fontSize = 3; //default
private: 
    std::string _textToDisplay;
    std::string _paramToDisplay;
    std::string getParamAsText(std::string textToDisplay, std::string paramToDisplay);
    int _spawnPosX, _spawnPosY;        
};