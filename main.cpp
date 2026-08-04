#include "raylib.h"
#include <cmath>
#include <pthread.h>
#include <random>


int main()
{
   const int WindowWidth = 800;
   const int WindowHeight = 450;

    InitWindow(WindowWidth, WindowHeight, "My First Game");

    struct MiddleText
    {
        float Font = 20;
        float X = 100;
        float Y = 200;
    };
    MiddleText text;

    struct RectPlayer
    {
        float Width = 200;
        float Height = 80;
        float X = 100.0f;
        float Y = 300.0;
        Color PlayerColor = BLUE;
        const float movespeed = 300.0f;
    };
    RectPlayer Player;

    struct Circle
    {
        float X = 100.0;
        float Y = 100.0;
        const float Radius = 30.0;
        float SpeedX = 0;
        float SpeedY = 0;
    };
    Circle Npc;

    struct Score
    {
        int Value = 0;
        Color ScoreColor = BLACK;
        float PositionX = 0;
        float PositionY = 0;
        float FontSize = 20;
        bool ShapesTouching = false;
    };
    Score Score;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-300, 300);
    float chosenX = dist(gen);
    float chosenY = dist(gen);
    Npc.SpeedX = chosenX;
    Npc.SpeedY = chosenY;

    while (!WindowShouldClose())
        {
            float rectUR = 0;
            float rectLR = 0;
            float closestX;
            float closestY;
            float dt = GetFrameTime();


            Npc.X += Npc.SpeedX * dt;
            Npc.Y += Npc.SpeedY * dt;

            if (Npc.X - Npc.Radius <= 0)
                {
                    Npc.X = Npc.Radius;
                    Npc.SpeedX = -Npc.SpeedX;
                }

            if (Npc.X + Npc.Radius >=WindowWidth)
                {
                    Npc.X = WindowWidth - Npc.Radius;
                    Npc.SpeedX = -Npc.SpeedX;
                }


            if (Npc.Y - Npc.Radius <= 0)
                {
                    Npc.Y = Npc.Radius;
                    Npc.SpeedY = -Npc.SpeedY;

                }

            if (Npc.Y + Npc.Radius >=WindowHeight)
                {
                    Npc.Y = WindowHeight - Npc.Radius;
                    Npc.SpeedY = -Npc.SpeedY;
                }

            if (IsKeyDown(KEY_RIGHT))
                {
                    Player.X += Player.movespeed * dt;
                }

            if (IsKeyDown(KEY_LEFT))
                {
                    Player.X -= Player.movespeed * dt;
                }


            if (IsKeyDown(KEY_UP))
                {
                    Player.Y -= Player.movespeed * dt;
                }

            if (IsKeyDown(KEY_DOWN))
                {
                    Player.Y += Player.movespeed * dt;
                }

            rectUR = Player.X + Player.Width;
            rectLR = Player.Y + Player.Height;

            if (Player.X <= 0)
                {
                    Player.X = 0;
                }
            else if (rectUR >=WindowWidth)
                {
                    Player.X = WindowWidth - Player.Width;
                }

            if (Player.Y <= 0)
                {
                    Player.Y = 0;
                }
            else if (rectLR >=WindowHeight)
                {
                    Player.Y = WindowHeight - Player.Height;
                }

            if (Npc.X < Player.X)
                {
                    closestX = Player.X;
                }
            else if (Npc.X > Player.X + Player.Width)
                {
                    closestX = Player.X + Player.Width;
                }
            else
                {
                    closestX = Npc.X;
                }

            if (Npc.Y < Player.Y)
                {
                    closestY = Player.Y;
                }
            else if (Npc.Y > Player.Y + Player.Height)
                {
                    closestY = Player.Y + Player.Height;
                }
            else
                {
                    closestY = Npc.Y;
                }


            float dx = Npc.X - closestX;
            float dy = Npc.Y - closestY;
            float distance = sqrt(dx*dx + dy*dy);

            if (distance < Npc.Radius && Score.ShapesTouching == false)
                {
                    Score.Value++;
                }

            if (distance < Npc.Radius)
                {
                    Player.PlayerColor = RED;
                    Score.ShapesTouching = true;
                }
            else
                {
                    Player.PlayerColor = BLUE;
                    Score.ShapesTouching = false;
                }

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("PlayBall", text.X, text.Y, text.Font, LIGHTGRAY);
            DrawText(TextFormat("Score: %i", Score.Value), Score.PositionX, Score.PositionY, Score.FontSize, Score.ScoreColor );
            DrawRectangle(Player.X, Player.Y, Player.Width, Player.Height, Player.PlayerColor);
            DrawCircle(Npc.X, Npc.Y, Npc.Radius, BLUE);
            EndDrawing();
        }

    CloseWindow();
}
