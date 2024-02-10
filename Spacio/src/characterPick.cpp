#include "characterPick.h"

void characterPick(Font Poppins, Font boldPoppins)
{
    SetMouseCursor(MOUSE_CURSOR_ARROW);

    Texture2D background = LoadTexture("../assets/images/chooseMenuBackground.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}