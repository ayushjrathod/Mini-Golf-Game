#include "ball.h"
#include <raylib.h>
#include <iostream>

void Ball::setInitialMousePos(float x, float y)
{
    initialMousePos.x = x;
    initialMousePos.y = y;
}

void Ball::setFinalMousePos(float x, float y)
{
    finalMousePos.x = x;
    finalMousePos.y = y;
}

void Ball::update()
{
    // Check Collision with the window
    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
    {
        velocity.y *= -1;
    }
    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0)
    {
        velocity.x *= -1;
    }
    if (CheckCollisionCircleRec(position, radius, Obs.rec))
    {
                // Calculate collision normal
                Vector2 collisionNormal = {0, 0};
                if (position.x < Obs.rec.x)
                {
                    collisionNormal.x = -1;
                }
                else if (position.x > Obs.rec.x + Obs.rec.width)
                {
                    collisionNormal.x = 1;
                }
                if (position.y < Obs.rec.y)
                {
                    collisionNormal.y = -1;
                }
                else if (position.y > Obs.rec.y + Obs.rec.height)
                {
                    collisionNormal.y = 1;
                }

                // Reflect ball velocity using the collision normal
                velocity = Reflect(velocity, collisionNormal);
    }

    if (CheckCollisionCircleRec(position, radius, Obs.rec1))
    {
                // Calculate collision normal
                Vector2 collisionNormal = {0, 0};
                if (position.x < Obs.rec1.x)
                {
                    collisionNormal.x = -1;
                }
                else if (position.x > Obs.rec1.x + Obs.rec1.width)
                {
                    collisionNormal.x = 1;
                }
                if (position.y < Obs.rec1.y)
                {
                    collisionNormal.y = -1;
                }
                else if (position.y > Obs.rec1.y + Obs.rec1.height)
                {
                    collisionNormal.y = 1;
                }

                // Reflect ball velocity using the collision normal
                velocity = Reflect(velocity, collisionNormal);
    }

    if (CheckCollisionCircleRec(position, radius, Obs.rec2))
    {
                // Calculate collision normal
                Vector2 collisionNormal = {0, 0};
                if (position.x < Obs.rec2.x)
                {
                    collisionNormal.x = -1;
                }
                else if (position.x > Obs.rec2.x + Obs.rec2.width)
                {
                    collisionNormal.x = 1;
                }
                if (position.y < Obs.rec2.y)
                {
                    collisionNormal.y = -1;
                }
                else if (position.y > Obs.rec2.y + Obs.rec2.height)
                {
                    collisionNormal.y = 1;
                }

                // Reflect ball velocity using the collision normal
                velocity = Reflect(velocity, collisionNormal);
    }

    if (CheckCollisionCircleRec(position, radius, Obs.rec3))
    {
                // Calculate collision normal
                Vector2 collisionNormal = {0, 0};
                if (position.x < Obs.rec3.x)
                {
                    collisionNormal.x = -1;
                }
                else if (position.x > Obs.rec3.x + Obs.rec3.width)
                {
                    collisionNormal.x = 1;
                }
                if (position.y < Obs.rec3.y)
                {
                    collisionNormal.y = -1;
                }
                else if (position.y > Obs.rec3.y + Obs.rec3.height)
                {
                    collisionNormal.y = 1;
                }

                // Reflect ball velocity using the collision normal
                velocity = Reflect(velocity, collisionNormal);
    }

    // Initial Mouse Position
    if (IsMouseButtonPressed(0))
    {
        float mouseX = GetMouseX();
        float mouseY = GetMouseY();
        setInitialMousePos(mouseX, mouseY);
    }

    if (IsMouseButtonReleased(0))
    {
        // Final Mouse Position
        float mouseX = GetMouseX();
        float mouseY = GetMouseY();
        setFinalMousePos(mouseX, mouseY);

        // Displacement Vector
        displacement = {finalMousePos.x - initialMousePos.x, finalMousePos.y - initialMousePos.y};

        // Magnitude
        magnitude = Vector2Length(displacement);

        // Time Of Flight
        timeOfFlight = magnitude / getDistance(finalMousePos, initialMousePos);

        // Velocity
        velocity.x = (displacement.x / timeOfFlight) * -1;
        velocity.y = (displacement.y / timeOfFlight) * -1;

        // Time variables
        deltaTime = GetFrameTime() * 5.0f;
    }
    else
    {
        // Updating Position of the ball
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;

        // Decreasing Velocity based on the friction and the time elapsed
        velocity.x *= (1.0f - friction * deltaTime);
        velocity.y *= (1.0f - friction * deltaTime);
    }
}
