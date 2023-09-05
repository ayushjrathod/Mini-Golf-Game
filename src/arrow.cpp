#include "arrow.h"
#include <raylib.h>

void Arrow::TexLoad(){

    texture2 = LoadTexture("assets/point.png");

    }

void Arrow::ArrowCor(float x, float y){

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsKeyDown(KEY_UP) )
    {
        startPosition = {x, y};
        isDragging = true;
    }

    else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_UP))
    {
        endPosition = GetMousePosition();
        isDragging = false;
    }
    else {
        isDragging = false;
    }

    if (isDragging)
    {
        Vector2 currentMousePosition = GetMousePosition();
        Vector2 lineVector = Vector2Subtract(currentMousePosition, startPosition);
        Vector2 lineDirection = Vector2Normalize(lineVector);
        lineLength = Vector2Length(lineVector);

        if (lineLength > MAX_LINE_LENGTH)
        {
            endPosition = Vector2Add(startPosition, Vector2Scale(lineDirection, MAX_LINE_LENGTH));
            arrowhead = endPosition;
        }

        else
        {
            endPosition = currentMousePosition;
            arrowhead = endPosition;
        }
    }

    arrowLength = Vector2Length(Vector2Subtract(startPosition, arrowhead));
    Vector2 direction = Vector2Subtract(arrowhead, startPosition);
    rotation = (atan2f(direction.y, direction.x) * RAD2DEG) - 90;
    // Define the source rectangle
    sourceRec ={ 0, 0, static_cast<float>(texture2.width), static_cast<float>(texture2.height) };
    //Npatch
    nPatchInfo = { sourceRec, 0, 32, 0, 32, NPATCH_THREE_PATCH_VERTICAL};
    //DestRec
    destRec = {startPosition.x, startPosition.y, 25, arrowLength};

    pivot = {static_cast<float>(texture2.width) / 2, static_cast<float>(texture2.height )/ 2 };

}
