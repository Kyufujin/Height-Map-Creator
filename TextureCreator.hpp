#pragma once
#include "raylib.h"

class TextureCreator{
public:
    Image blankImg = GenImageColor(128,128,BLACK);
    Image createImage();
    void saveGeneratedMap();    
};