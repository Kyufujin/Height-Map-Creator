#pragma once
#include "UI.hpp"
#include "raylib.h"
#include <string>

class TextField : public UI{
public:
    TextField(std::string textToDisplay, std::string paramToDisplay);
    void Display() override;
    int fontSize = 3; //default
private:
    std::string getParamAsText(std::string textToDisplay, std::string paramToDisplay);
    std::string _textToDisplay;
    std::string _paramToDisplay;
};