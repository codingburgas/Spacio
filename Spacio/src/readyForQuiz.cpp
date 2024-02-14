#include "readyForQuiz.h"
void readyForQuiz()
{
    SetMouseCursor(MOUSE_CURSOR_ARROW);
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Test", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
}