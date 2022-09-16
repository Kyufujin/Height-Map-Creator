#pragma once
#include "UI.hpp"
#include "raylib.h"
#include "TextureCreator.hpp"
#include <string>
#include <iomanip>

class TextField : public UI{
public:
    TextField(TextureCreator& generatorParamObj, std::string textToDisplay, std::string paramToDisplay, int spawnPosX, int spawnPosY);
    void Display() override;
    void SetParamOnActionSubtract();
    void SetParamOnActionAdd();
    static constexpr int fontSize = 3; //default
private:
    TextureCreator _generatedParamObj;
    std::string _textToDisplay;
    std::string _paramToDisplay;
    std::string getParamAsText(std::string textToDisplay, std::string paramToDisplay);
    int _spawnPosX, _spawnPosY;        
};