#include "chooseLearningStyle.h"

bool cursorOnRectangle(Rectangle rectangle) {
    if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
        return true;
    }

    return false;
}

void mouseCursorLearningStyle(Rectangle reading, Rectangle playing)
{
    if (CheckCollisionPointRec(GetMousePosition(), reading)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), playing)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

void chooseLearningStyle() {
	Texture2D background = LoadTexture("../assets/images/chooseLearningStyleBg.png");

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    Rectangle reading = { 283, 302, 295, 295 };
    Rectangle playing = { 830,304 ,295 ,295 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTextEx(boldPoppins, "How do you want to learn?", Vector2(336, 137), 64, 5, WHITE);
        DrawTextEx(boldPoppins, "By reading", Vector2(371, 605), 32, 5, WHITE);
        DrawTextEx(boldPoppins, "By playing", Vector2(909, 605), 32, 5, WHITE);

        mouseCursorLearningStyle(reading, playing);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (cursorOnRectangle(reading)) {
                characterPick(Poppins, boldPoppins);
                break;
            }
            if (cursorOnRectangle(playing)) {
                spaceShip();
                break;
            }
        }

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}