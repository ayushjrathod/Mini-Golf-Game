#include "raylib.h"

class background {
 protected:
    Texture2D backgroundImage;
    Vector2 backgroundPos{0,0};
    float screenHeight = 450, screenWidth = 800;
 public:
      void ImportTexture();
      void DrawTexture();
      void UnloadTexture();
};

class backgroundMain : public background {
 public:
      void ImportTexture();
      void DrawTexture();
      void UnloadTexture();
};

void backgroundMain::ImportTexture(){
      Image background = LoadImage("assets/bg.png");
      backgroundImage = LoadTextureFromImage(background);
      UnloadImage(background);
}

void backgroundMain::DrawTexture(){
    for(int y=0; y < screenHeight; y += backgroundImage.height){
        for(int x = 0; x < screenWidth; x += backgroundImage.width){
            ::DrawTexture(backgroundImage,x,y,WHITE);
        }
    }
}

void backgroundMain::UnloadTexture(){
    ::UnloadTexture(backgroundImage);
}
