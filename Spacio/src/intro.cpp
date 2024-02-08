#include "intro.h"

void intro() {

    Texture2D background = LoadTexture("../assets/images/introBackground.png");
    Rectangle digIn = { 500, 400, 280, 94 };

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawRectangleRec(digIn, GetColor(0X2C2C2Cff));
        DrawTextEx(boldPoppins, "Dig In", Vector2(540, 410), 70, 10, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), digIn)) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }
        else SetMouseCursor(MOUSE_CURSOR_ARROW);

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(Poppins);
}
