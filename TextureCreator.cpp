#include "TextureCreator.hpp"

TextureCreator::TextureCreator(int defaultFrequency) : frequency(defaultFrequency){
    setGeneratedImage();
    tintMap();
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

