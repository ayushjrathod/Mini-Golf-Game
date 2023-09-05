#include "raylib.h"

class ScoreBoard{
  public:
    int Score = 0, Atempt = 0;
     void CheckIfMousePressed(){
         if (IsKeyPressed(MOUSE_LEFT_BUTTON))
             Atempt++;
     }

};
