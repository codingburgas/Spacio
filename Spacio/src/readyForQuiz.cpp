#include "readyForQuiz.h"

void cursor(Rectangle buttonYes, Rectangle buttonNo)
{
    if (CheckCollisionPointRec(GetMousePosition(), buttonYes)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), buttonNo)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

void Quiz()
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
   

    Texture2D background = LoadTexture("../assets/images/readyForBackground.png");

    Rectangle buttonYes = { 648, 500, 150, 40 };
    Rectangle ButtonNo = { 648, 580, 180, 40 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        void cursor(Rectangle buttonYes, Rectangle buttonNo);

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawText("Are you ready for a quiz", 500, 50, 35, LIGHTGRAY);

        EndDrawing();
    }
}