#include "characterPick.h"

void characterPick(Font Poppins, Font boldPoppins)
{
    SetMouseCursor(MOUSE_CURSOR_ARROW);

    Texture2D background = LoadTexture("../assets/images/characterPickBackground.png");
    
    Texture2D girlAstrounat = LoadTexture("../assets/images/girlAstronaut.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTexture(girlAstrounat, 1018, 180, RAYWHITE);

        DrawTextEx(boldPoppins, "Choose a companion", Vector2(350, 60), 75, 5, WHITE);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}