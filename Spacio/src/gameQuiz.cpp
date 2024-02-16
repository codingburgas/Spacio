#include "gameQuiz.h"

void gameQuiz()
{
	Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
	Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextEx(boldPoppins, "Are you ready for a quiz?", Vector2(450, 50), 50, 5, WHITE);

        EndDrawing();
    }
}