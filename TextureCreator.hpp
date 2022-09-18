#pragma once
#include "raylib.h"
#include <string>
#include <map>

class TextureCreator{
public:
    TextureCreator(int defaultFrequency, float defaultForce, int defaultFlat);
    Image blankImg = GenImageColor(128,128,BLACK);
    Image getGeneratedImage();
    Texture2D getGeneratedTexture();
    Mesh getGeneratedMesh();
    Model getGeneratedModel();
    Vector3 getGeneratedMapPosition();
    void saveGeneratedMap();
    void setGeneratedImage();
    void eraseData();
    void defineBaseConfig();
    float force;
    int flat;
    int frequency;

    Texture2D generatedTexture;
    Mesh generatedMesh;
    Model generatedModel;
    Vector3 generatedMapPosition;
private:  
    void fillTerrain(Image & _generatedImage);
    Image _generatedImage;
    Image createImage();
    void tintMap();
};


enum class CreatorParameters{
    Force,
    Flat,
    Frequency,
    invalidParam
};

CreatorParameters returnParameter(std::string param);