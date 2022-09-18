#include "raylib.h"
#include "UI.hpp"
#include "TextureCreator.hpp"

class ButtonGenerate : public UI{
public:
    ButtonGenerate(TextureCreator& generatedObj, float spawnPosX, float spawnPosY);
private:
    bool CheckCollision();
    void Display() override;
    TextureCreator& _generatedObj;
    float _spawnPosX, _spawnPosY;   
    static constexpr int buttonSize = 40; // width and height value of the button
};