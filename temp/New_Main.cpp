#include "Screen.cpp"


typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;
UI ui;

int main(void)
{
        int cat;
     //  Texture2D cat = LoadTexture("golfbg.png");

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Causual Golf Game");

    GameScreen currentScreen = LOGO;
   

    SetTargetFPS(60);              
    

   
    while (!WindowShouldClose())   
    {
        
        switch(currentScreen)
        {
            case LOGO:
            {
             currentScreen = TITLE;
            } break;
            case TITLE:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break; 
            case ENDING:
            {
                
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {

                case TITLE:
                {
                      // Texture2D cat = LoadTexture("bg.png");
                    ui.TitleScreen();
                } break;
               /* case GAMEPLAY:
                {
                   
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break; */
                case ENDING:
                {
                
                    ui.EndingScreen();

                } break;
                default: break;
            }

        EndDrawing();
    }

    CloseWindow();        
   

    return 0;
}