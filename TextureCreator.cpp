#include "TextureCreator.hpp"

Image TextureCreator::createImage(){
    Image generatedImg = blankImg;   
    return generatedImg = GenImageCellular(32,32,2);
}

void TextureCreator::saveGeneratedMap(){
    ExportImage(TextureCreator::createImage(),"HeightMap.png");
}