#include "TextField.hpp"

TextField::TextField(std::string textToDisplay, std::string paramToDisplay) : _textToDisplay(textToDisplay),
                                                                              _paramToDisplay(paramToDisplay)
{}

void TextField::Display(){
    const char * textField = getParamAsText(_textToDisplay, _paramToDisplay).c_str();
    DrawText(textField, 60, 20, fontSize, GREEN);
}

std::string TextField::getParamAsText(std::string textToDisplay, std::string paramToDisplay){
    return textToDisplay + "\n" + paramToDisplay;
}