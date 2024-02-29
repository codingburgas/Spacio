#include "intro.h"
#include "mainMenu.h"
#include "basicData.h"


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

void InitIntroWindow()
{
    basicData.background = LoadTexture("../assets/images/introBackground.png");
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 200, NULL, NULL);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 200, NULL, NULL);

    introData.digIn = { 490, 400, 280, 94 };
    introData.quit = { 490, 520, 280, 94 };
    introData.quitButton = false;
}

void intro(GameState& state)
{
    DrawTexture(basicData.background, 0, 0, RAYWHITE);

    DrawRectangleRec(introData.digIn, GetColor(0X2C2C2Cff));
    DrawTextEx(basicData.boldPoppins, "Dig In", Vector2(540, 410), 70, 5, WHITE);

    DrawRectangleRec(introData.quit, GetColor(0X2C2C2Cff));
    DrawTextEx(basicData.boldPoppins, "Quit", Vector2(560, 530), 70, 5, WHITE);

    mouseCursor(introData.digIn, introData.quit);

    if (buttonActions(introData.digIn, introData.quit, buttonTypes::QUIT))
    {
        state = GameState::NONE;
    }

    if (buttonActions(introData.digIn, introData.quit, buttonTypes::DIGIN))
    {
        state = GameState::UserName;
    }
}
