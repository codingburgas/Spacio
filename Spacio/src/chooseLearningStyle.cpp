#include "chooseLearningStyle.h"
#include "characterPick.h"
#include "SpaceShip.h"

void chooseLearningStyle() {
	Texture2D background = LoadTexture("../assets/images/chooseLearningStyleBg.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}