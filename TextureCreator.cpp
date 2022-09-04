#include "TextureCreator.hpp"

TextureCreator::TextureCreator(int defaultFrequency) : frequency(defaultFrequency){
    setGeneratedImage();
}

Image TextureCreator::createImage(){
    Image generatedImg = blankImg;   
    return generatedImg = GenImageCellular(32,32,frequency);
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

