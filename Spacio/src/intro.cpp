#include "intro.h"

void mouseCursor(Rectangle digIn, Rectangle quit)
{
    if (CheckCollisionPointRec(GetMousePosition(), digIn)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else SetMouseCursor(MOUSE_CURSOR_ARROW);

    if (CheckCollisionPointRec(GetMousePosition(), quit)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
}

bool buttonActions(Rectangle digIn, Rectangle quit, buttonTypes type)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(GetMousePosition(), quit) && type == buttonTypes::QUIT) {
            return true;
        }
        if (CheckCollisionPointRec(GetMousePosition(), digIn) && type == buttonTypes::DIGIN) {
            return true;
        }
    }
    return false;
}


void intro() {

    Texture2D background = LoadTexture("../assets/images/introBackground.png");

    Rectangle digIn = { 490, 400, 280, 94 };
    Rectangle quit{ 490, 520, 280, 94 };

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    bool quitButton = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawRectangleRec(digIn, GetColor(0X2C2C2Cff));
        DrawTextEx(boldPoppins, "Dig In", Vector2(540, 410), 70, 5, WHITE);

        DrawRectangleRec(quit, GetColor(0X2C2C2Cff));
        DrawTextEx(boldPoppins, "Quit", Vector2(560, 530), 70, 5, WHITE);

        mouseCursor(digIn, quit);

        if (buttonActions(digIn, quit, buttonTypes::QUIT))
        {
            break;
        }

        if (buttonActions(digIn, quit, buttonTypes::DIGIN))
        {
            userName();
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadFont(Poppins);
}
