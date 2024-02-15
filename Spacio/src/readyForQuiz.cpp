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
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/readyBackground.png");
    Texture2D starYes = LoadTexture("../assets/images/starYes.png");
    Texture2D starNo = LoadTexture("../assets/images/starNo.png");

    Rectangle buttonYes = { 648, 500, 150, 40 };
    Rectangle ButtonNo = { 648, 580, 180, 40 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        void cursor(Rectangle buttonYes, Rectangle buttonNo);

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTexture(starYes, 800, 150, RAYWHITE);
        DrawTexture(starNo, 800, 450, RAYWHITE);

        DrawTextEx(boldPoppins, "Are you ready for a quiz", Vector2(450, 50), 50, 5, WHITE);

        EndDrawing();
    }
}