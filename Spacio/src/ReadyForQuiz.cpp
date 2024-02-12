#include "ReadyForQuiz.h"

    int main()
    {   
        const int screenWidth = 1440;
        const int screenHeight = 900;

        InitWindow(screenWidth, screenHeight, "Spacio");

        SetTargetFPS(60);
    }

    while(!WindowShouldClose() == true)
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }