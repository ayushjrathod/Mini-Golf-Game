#include <raylib.h>
#include <raymath.h>
#include <iostream>
#define MAX_LINE_LENGTH 200


#include "ball.cpp"
#include "cup.h"
#include "arrow.cpp"





Ball ball;
Cup cup;
Arrow arrow;

int main(void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "Golf v1.1");
    SetTargetFPS(60);

    cup.radius = 10;
    cup.cupPosition.x = (float)screenWidth / 4;
    cup.cupPosition.y = (float)screenHeight / 4;

    ball.radius = 7;
    ball.position.x = (float)screenWidth / 2;
    ball.position.y = (float)screenHeight / 2;

    arrow.TexLoad();

    while (!WindowShouldClose())
    {
        arrow.ArrowCor(ball.position.x, ball.position.y);

        BeginDrawing();

        ClearBackground(SKYBLUE);
        arrow.Draw();

        ball.update();


        DrawCircleV(cup.cupPosition, cup.radius, GRAY);

        ball.draw();

        if (cup.checkWin(ball.position, cup))
        {
            std::cout << "Congratulations! You have won!" << std:: endl;
            break;
        }

        EndDrawing();
    }

    arrow.TextUnload();
    CloseWindow();

    return 0;

}
