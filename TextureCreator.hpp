#pragma once
#include "raylib.h"

class TextureCreator{
public:
    TextureCreator(int defaultFrequency);
    int frequency;
    Image blankImg = GenImageColor(128,128,BLACK);
    Image getGeneratedImage();
    void saveGeneratedMap();
    void setGeneratedImage();
    void tintMap();
private:  
    Image _generatedImage;
    Image createImage();
};