#include "raylib.h"

int main()
{


   const int WindowWidth = 800;
   const int WindowHeight = 450;

    InitWindow(WindowWidth, WindowHeight, "My First Game");
    float TextFont = 20;
    float TextX = 190;
    float TextY = 200;
    float rectWidth = 200;
    float rectHeight = 80;
    float rectX = 100.0f;
    float rectY = 300.0;
    const float movespeed = 300.0f;
    float rectUR = 0;
    float rectLR = 0;

        while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT))
        {
            rectX += movespeed * dt;

        }

        if (IsKeyDown(KEY_LEFT))
        {
            rectX -= movespeed * dt;

        }


        if (IsKeyDown(KEY_UP))
        {
            rectY -= movespeed * dt;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            rectY += movespeed * dt;
        }

        rectUR = rectX + rectWidth;
        rectLR = rectY + rectHeight;

        if (rectX <= 0) {
            rectX = 0;
        }
        else if (rectUR >=WindowWidth) {
            rectX = WindowWidth - rectWidth;
        }

        if (rectY <= 0) {
            rectY = 0;
        }
        else if (rectLR >=WindowHeight) {
            rectY = WindowHeight - rectHeight;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Gotter", TextX, TextY, TextFont, LIGHTGRAY);
        DrawRectangle(rectX, rectY, rectWidth, rectHeight, BLUE);
        EndDrawing();


    }

        CloseWindow();

}
