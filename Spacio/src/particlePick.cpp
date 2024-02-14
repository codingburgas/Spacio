#include "particlePick.h"
#include <iostream>

bool mouseCursorOnRectangle(Rectangle rectangle) {
	if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
		return true;
	}

	return false;
}

void mouseCursorParticles(Rectangle masslessParticle, Rectangle massParticle)
{
    if (CheckCollisionPointRec(GetMousePosition(), masslessParticle)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), massParticle)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

void particlePick() {
	Texture2D background = LoadTexture("../assets/images/chooseParticleBg.png");
	


	Rectangle masslessParticle = { 283, 302, 295, 295 };
	Rectangle massParticle = { 830,304 ,295 ,295 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);

        mouseCursorParticles(masslessParticle, massParticle);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
}