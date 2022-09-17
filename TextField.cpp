#include "TextField.hpp"

TextField::TextField(std::string textToDisplay, std::string paramToDisplay, int spawnPosX, int spawnPosY):
                                                                                                            _textToDisplay(textToDisplay),
                                                                                                            _paramToDisplay(paramToDisplay),
                                                                                                            _spawnPosX(spawnPosX),
                                                                                                            _spawnPosY(spawnPosY)
{}

void TextField::Display(){
    const char * textField = getParamAsText(_textToDisplay, _paramToDisplay).c_str();
    DrawText(textField, _spawnPosX, _spawnPosY, fontSize, GREEN);
}

std::string TextField::getParamAsText(std::string textToDisplay, std::string paramToDisplay){
    return textToDisplay + "\n" + paramToDisplay;
}
