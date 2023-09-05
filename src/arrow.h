#include <raylib.h>
#include <raymath.h>
#include <iostream>
#define MAX_LINE_LENGTH 200


// #include "ball.cpp"
// #include "cup.h"
//#include "arrow.h"



class Arrow
{
    Vector2 startPosition, endPosition, arrowhead, lineDirection, direction;
    Vector2 lineVector, pivot, currentMousePosition;

    bool isDragging;
    Texture2D texture2;

    float arrowLength, rotation, lineLength;
    Rectangle sourceRec, destRec;

    NPatchInfo nPatchInfo;

   public:

    void TexLoad();
    void ArrowCor(float x, float y);
    void Draw()
    {
    if (isDragging)
        {
            DrawTextureNPatch(texture2, nPatchInfo, destRec, pivot, rotation, WHITE );
        }
    }
    void TextUnload(){
        UnloadTexture(texture2);
    }
};
