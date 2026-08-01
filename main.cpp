#include "raylib.h"
#include <cmath>

int main()
{


   const int WindowWidth = 800;
   const int WindowHeight = 450;

    InitWindow(WindowWidth, WindowHeight, "My First Game");

struct MiddleText{
    float Font = 20;
    float X = 100;
    float Y = 200;
    };
    MiddleText text;

struct RectPlayer{
    float Width = 200;
    float Height = 80;
    float X = 100.0f;
    float Y = 300.0;
    };
    RectPlayer Player;

    const float movespeed = 300.0f;
    float rectUR = 0;
    float rectLR = 0;

    struct Circle {
    float X = 100.0;
    float Y = 100.0;
    const float Radius = 30.0;
    };
    Circle Npc;

    float CircleSpeed = 150.0f;

    float closestX;
    float closestY;

        while (!WindowShouldClose())
    {
        float dt = GetFrameTime();


        Npc.X += CircleSpeed * dt;

        if (Npc.X - Npc.Radius <= 0)
            {
                Npc.X = Npc.Radius;
                CircleSpeed = -CircleSpeed;

            }

        if (Npc.X + Npc.Radius >=WindowWidth)
        {
            Npc.X = WindowWidth - Npc.Radius;
            CircleSpeed = -CircleSpeed;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            Player.X += movespeed * dt;

        }

        if (IsKeyDown(KEY_LEFT))
        {
            Player.X -= movespeed * dt;

        }


        if (IsKeyDown(KEY_UP))
        {
            Player.Y -= movespeed * dt;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            Player.Y += movespeed * dt;
        }

        rectUR = Player.X + Player.Width;
        rectLR = Player.Y + Player.Height;

        if (Player.X <= 0) {
            Player.X = 0;
        }
        else if (rectUR >=WindowWidth) {
            Player.X = WindowWidth - Player.Width;
        }

        if (Player.Y <= 0) {
            Player.Y = 0;
        }
        else if (rectLR >=WindowHeight) {
            Player.Y = WindowHeight - Player.Height;
        }

        if (Npc.X < Player.X) {
            closestX = Player.X;
        }
        else if (Npc.X > Player.X + Player.Width) {
        closestX = Player.X + Player.Width;
        }
        else {
        closestX = Npc.X;
        }

        if (Npc.Y < Player.Y) {
        closestY = Player.Y;
        }
        else if (Npc.Y > Player.Y + Player.Height) {
        closestY = Player.Y + Player.Height;
        }
        else {
            closestY = Npc.Y;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Gotter", text.X, text.Y, text.Font, LIGHTGRAY);
        DrawRectangle(Player.X, Player.Y, Player.Width, Player.Height, BLUE);
        DrawCircle(Npc.X, Npc.Y, Npc.Radius, BLUE);
        EndDrawing();


    }

        CloseWindow();

}
