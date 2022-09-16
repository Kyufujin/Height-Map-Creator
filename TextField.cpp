#include "TextField.hpp"

TextField::TextField(TextureCreator& generatedParamObj, std::string textToDisplay, std::string paramToDisplay, int spawnPosX, int spawnPosY):
                                                                                                            _generatedParamObj(generatedParamObj),
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

void TextField::SetParamOnActionSubtract(){
    switch(returnParameter(_paramToDisplay))
    {
        case CreatorParameters::force: {
            // force action 
            _generatedParamObj.force-=1;
            break;
        }

        case CreatorParameters::flat: {
            // flat action
            _generatedParamObj.flat-=1;
            break;
        }

        case CreatorParameters::frequency: {
            // frequency action
            _generatedParamObj.frequency-=1;
            break;
        }

        default: {
            break;
        }
    }
}

void TextField::SetParamOnActionAdd(){
    switch(returnParameter(_paramToDisplay))
    {
        case CreatorParameters::force: {
            // force action 
            _generatedParamObj.force+=1;
            break;
        }

        case CreatorParameters::flat: {
            // flat action
            _generatedParamObj.flat+=1;
            break;
        }

        case CreatorParameters::frequency: {
            // frequency action
            _generatedParamObj.frequency+=1;
            break;
        }

        default: {
            break;
        }
    }
}

