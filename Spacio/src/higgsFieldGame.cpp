#include "higgsFieldGame.h"

void HiggsFieldGame(bool hasMass) {
	Texture2D background = LoadTexture("../assets/images/higgsfieldBg.png");
    Texture2D particle = LoadTexture("../assets/images/particle.png");



	Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
	Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);
       
        DrawTextEx(boldPoppins, "Mass:", Vector2(114, 68), 48, 5, WHITE);
        DrawTextEx(boldPoppins, "Speed:", Vector2(117, 140), 48, 5, WHITE);
        DrawTextEx(boldPoppins, "Lorem ipsum dolor sit amet", Vector2(665, 59), 40, 5, WHITE);

        DrawTexture(particle, -1272, 707, RAYWHITE);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    UnloadTexture(background);
    UnloadFont(Poppins);
}