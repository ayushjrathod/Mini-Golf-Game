#pragma once
#include <raylib.h>
#include <raymath.h>
#include "Obstacles.cpp"



class Ball
{
private:
    Vector2 initialMousePos, finalMousePos, displacement;
    float magnitude, deltaTime, timeOfFlight;
    float friction = 0.1f;
    Texture2D ballimg;
    Obstacle Obs;
    int Score = 0;

public:
    Vector2 position, velocity;
    int radius;

    void LoadBall(){
        Image bl = LoadImage("assets/ball.png");
        ballimg = LoadTextureFromImage(bl);
        UnloadImage(bl);
    }
    void GetInput(Obstacle O){
        Obs = O;
    }
    void draw()
    {
        DrawTextureV(ballimg, position, WHITE);
    }

    Vector2 getInitialMousePos()
    {
        return initialMousePos;
    }

    void update();
    void setInitialMousePos(float x, float y);
    void setFinalMousePos(float x, float y);

    float getDistance(Vector2 a, Vector2 b)
    {
        return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
    }

    Vector2 Reflect(Vector2 v, Vector2 normal)
    {
    return Vector2Subtract(v, Vector2Scale(normal, 2 * Vector2DotProduct(v, normal)));
    }

    int GetScore(){
        return Score;
    }

};
