#include <raylib.h>
#include <string>

class UI {
    typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING, WINING } GameScreen;
    GameScreen currentScreen;
    float screenHeight = 450, screenWidth = 800;
    int score = 0;
  public:
    void TitleScreen(){
        Image StartBackground = LoadImage("assets/bg.png");
        Texture2D bg1 = LoadTextureFromImage(StartBackground);
        UnloadImage(StartBackground);

        for(int y=0; y < screenHeight; y += bg1.height)
        {
            for(int x = 0; x < screenWidth; x += bg1.width)
            {
                DrawTexture(bg1,x,y,WHITE);
            }

        }
        Image Logo = LoadImage("assets/l3.png");
        Texture2D L1 = LoadTextureFromImage(Logo);
        UnloadImage(Logo);
        DrawTexture(L1,150,100,WHITE);
    }
    void EndingScreen(){
        // DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
        // DrawText("Congratulatons", 250, 20, 40, DARKBLUE);
        // DrawText("You Have Completed The Game", 100,100, 40, DARKBLUE);
        // DrawText(" ", 120, 220, 20, DARKBLUE);
        Image endbag = LoadImage("assets/endbg2.png");
        Texture2D E1 = LoadTextureFromImage(endbag);
        UnloadImage(endbag);
        DrawTexture(E1,0,0,WHITE);
        //UnloadTexture(E1);
    }
    void GetScore(int Score){
        score = Score;
    }
    void WiningScreen(){
        DrawRectangle(0, 0, screenWidth, screenHeight, RED);
        DrawText("Congratulatons", 250, 20, 40, DARKBLUE);
        DrawText( "Score : 1", 100,100, 40, DARKBLUE);
        DrawText(" ", 120, 220, 20, DARKBLUE);
    }
};
