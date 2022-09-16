#include "TextureCreator.hpp"

TextureCreator::TextureCreator(int defaultFrequency, float defaultForce, int defaultFlat) : frequency(defaultFrequency)
                                                                                            ,force(defaultForce)
                                                                                            ,flat(defaultFlat)
{
    setGeneratedImage();
    tintMap();    
    fillTerrain(_generatedImage);
    ImageColorContrast(&_generatedImage, force);
    ImageColorBrightness(&_generatedImage, flat);
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

CreatorParameters returnParameter(std::string param){
    static const std::map<std::string, CreatorParameters> paramStrings {
        {"force", CreatorParameters::force},
        {"flat", CreatorParameters::flat},
        {"frequency", CreatorParameters::frequency}
    };

    auto iter = paramStrings.find(param);
    if(iter != paramStrings.end()){
        return iter->second;
    }
    
    return CreatorParameters::invalidParam;
}
