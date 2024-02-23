#include "chooseLearningStyle.h"
#include "characterPick.h"
#include "SpaceShip.h"

void chooseLearningStyle() {
	Texture2D background = LoadTexture("../assets/images/chooseLearningStyleBg.png");

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTextEx(boldPoppins, "How do you want to learn?", Vector2(336, 137), 64, 5, WHITE);
        DrawTextEx(boldPoppins, "By reading", Vector2(371, 605), 32, 5, WHITE);
        DrawTextEx(boldPoppins, "By playing", Vector2(909, 605), 32, 5, WHITE);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}