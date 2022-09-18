#include "TextureCreator.hpp"

TextureCreator::TextureCreator(int defaultFrequency, float defaultForce, int defaultFlat) : frequency(defaultFrequency)
                                                                                            ,force(defaultForce)
                                                                                            ,flat(defaultFlat)
{    
    defineBaseConfig();
}

void TextureCreator::defineBaseConfig(){
    setGeneratedImage();
    tintMap();    
    fillTerrain(_generatedImage);
    ImageColorContrast(&_generatedImage, force);
    ImageColorBrightness(&_generatedImage, flat);
    generatedTexture = getGeneratedTexture();
    generatedMesh = getGeneratedMesh();
    generatedModel = getGeneratedModel();
    generatedMapPosition = getGeneratedMapPosition();
    generatedModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = getGeneratedTexture();// Set map diffuse texture
    UnloadImage(getGeneratedImage());                     // Unload heightmap image from RAM, already uploaded to VRAM
}

Texture2D TextureCreator::getGeneratedTexture(){
    return LoadTextureFromImage(getGeneratedImage());                // Convert image to texture (VRAM)
}
Mesh TextureCreator::getGeneratedMesh(){
    return GenMeshHeightmap(getGeneratedImage(), (Vector3){ 16, 6, 16 });    // Generate heightmap mesh (RAM and VRAM)
}
Model TextureCreator::getGeneratedModel(){
    return LoadModelFromMesh(getGeneratedMesh()); // Load model from generated mesh
}
Vector3 TextureCreator::getGeneratedMapPosition(){
    return  { -8.0f, 0.0f, -8.0f };  // Define model position
}

Image TextureCreator::createImage(){
    Image generatedImg = blankImg;   
    return generatedImg = GenImageCellular(128,128,frequency);
}

Image TextureCreator::getGeneratedImage(){
    return _generatedImage;
}

void TextureCreator::saveGeneratedMap(){
    ExportImage(_generatedImage,"HeightMap.png");
}

void TextureCreator::setGeneratedImage(){
    _generatedImage = TextureCreator::createImage();
}

void TextureCreator::tintMap(){
    ImageColorTint(&_generatedImage, WHITE);
}

void TextureCreator::fillTerrain(Image & _generatedImage){
    unsigned char edgeColor = 0;
    for(int i = 0; i<=3; i++){       
        ImageDrawRectangleLines(&_generatedImage, {
        static_cast<float>(i), static_cast<float>(i), 
        static_cast<float>(128) - (i * 2),
        static_cast<float>(128) - (i * 2)},
        1, {edgeColor,edgeColor,edgeColor,255});
        edgeColor+=10; // rectangleLines contain a constructor for a rectangle 
    }  
}

void TextureCreator::eraseData(){
    UnloadTexture(generatedTexture);                                        // Unload texture
    UnloadModel(generatedModel);                                           // Unload model
}

CreatorParameters returnParameter(std::string param){
    static const std::map<std::string, CreatorParameters> paramStrings {
        {"Force", CreatorParameters::Force},
        {"Flat", CreatorParameters::Flat},
        {"Frequency", CreatorParameters::Frequency}
    };

    auto iter = paramStrings.find(param);
    if(iter != paramStrings.end()){
        return iter->second;
    }
    return CreatorParameters::invalidParam;
}


