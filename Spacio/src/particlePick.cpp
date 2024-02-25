#include "particlePick.h"
#include "higgsFieldGame.h"
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

void particlePick(std::string userNameStr, bool girlVoice, bool boyVoice) {
	Texture2D background = LoadTexture("../assets/images/chooseParticleBg.png");
	

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

	Rectangle masslessParticle = { 283, 302, 295, 295 };
	Rectangle massParticle = { 830,304 ,295 ,295 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTextEx(boldPoppins, "What do you want to be?", Vector2(336, 118), 64, 5, WHITE);
        DrawTextEx(boldPoppins, "Massless particle ", Vector2(294, 605), 32, 5, WHITE);
        DrawTextEx(boldPoppins, "Particle with mass", Vector2(835, 595), 32, 5, WHITE);


        mouseCursorParticles(masslessParticle, massParticle);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (mouseCursorOnRectangle(masslessParticle)) {
                HiggsFieldGame(false, userNameStr, girlVoice, boyVoice);
                break;
            }
            if (mouseCursorOnRectangle(massParticle)) {
                HiggsFieldGame(true, userNameStr, girlVoice, boyVoice);
                break;
            }
        }

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    UnloadTexture(background);
    UnloadFont(Poppins);
}