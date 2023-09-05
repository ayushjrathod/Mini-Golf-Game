

#include "raylib.h"



typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;
GameScreen currentScreen;
float screenHeight, screenWidth;


void initial()
{
        //int cat;
     //Texture2D cat = LoadTexture("golfbg.png");
     //Vector2 backgroundPos{0,0};

    screenWidth = 800;
    screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Causual Golf Game");
    currentScreen = LOGO;
            
    
}
  
void input()
{   
   initial();
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
       
    }   
}

    void UIDrawing()
    {
        initial();
       input();
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {

                case TITLE:
                {
                      // Texture2D cat = LoadTexture("bg.png");
                       

                    DrawRectangle(0, 0, screenWidth, screenHeight, RAYWHITE);
                    DrawText("Casual Mini Golf Game", 180, 20, 40, DARKGREEN);
                    DrawText("Press Enter or Tap to Start Game ", 120, 150, 30, DARKGREEN);

                } break;
               /* case GAMEPLAY:
                {
                   
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break; */
                case ENDING:
                {
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("Congratulatons", 250, 20, 40, DARKBLUE);
                    DrawText("You Have Completed The Game", 100,100, 40, DARKBLUE);
                    DrawText(" ", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
    }
    
    void club()   //This clubs all finctions.
   {
      initial();
      input();
      UIDrawing();
        
   } 
   


int main()
{
   initial();
   input();
   UIDrawing();
   
   CloseWindow();        

    
}
