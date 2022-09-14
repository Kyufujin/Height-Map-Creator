#pragma once
#include "raylib.h"

class TextureCreator{
public:
    TextureCreator(int defaultFrequency, float defaultForce, int defaultFlat);
    Image blankImg = GenImageColor(128,128,BLACK);
    Image getGeneratedImage();
    void saveGeneratedMap();
    void setGeneratedImage();
    void tintMap();
    float force;
    int flat;
    int frequency;
private:  
    void fillTerrain(Image & _generatedImage);
    Image _generatedImage;
    Image createImage();
};