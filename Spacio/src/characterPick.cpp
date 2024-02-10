#include "characterPick.h"
#include <iostream>

void mouseCursorAstronauts(Rectangle boyAstronaut, Rectangle girlAstronaut)
{
    if (CheckCollisionPointRec(GetMousePosition(), boyAstronaut)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), girlAstronaut)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

bool girlVoice = false;
bool boyVoice = false;

bool pickVoice(Rectangle boyBox, Rectangle girlBox)
{

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(GetMousePosition(), boyBox)) {
            boyVoice = true;
        }
        if (CheckCollisionPointRec(GetMousePosition(), girlBox)) {
            girlVoice = true;
        }
    }

    return girlVoice || boyVoice;
}

void characterPick(Font Poppins, Font boldPoppins)
{
    Texture2D background = LoadTexture("../assets/images/characterPickBackground.png");
    
    Texture2D boyAstronaut = LoadTexture("../assets/images/boyAstronaut.png");
    Texture2D girlAstronaut = LoadTexture("../assets/images/girlAstronaut.png");

    Rectangle boyBox = { 285, 200, 161, 204 };
    Rectangle girlBox = { 1018, 180, 214, 214 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(girlAstronaut, 1018, 180, RAYWHITE);
        DrawTexture(boyAstronaut, 285, 200, RAYWHITE);

        mouseCursorAstronauts(boyBox, girlBox);

        DrawTextEx(boldPoppins, "Choose a companion", Vector2(350, 60), 75, 5, WHITE);

        pickVoice(boyBox, girlBox);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

}