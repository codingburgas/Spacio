#include "pickPlanet.h"

void pickPlanet()
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadImage();
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTextEx(Poppins, "Which celestial object are you visiting today?", Vector2( 210, 150), 20, 5, RAYWHITE);

        EndDrawing();
    }

}