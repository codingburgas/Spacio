#include "endScreen.h"


void endScreen() {
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);
    Texture2D background = LoadTexture("../assets/images/endScreenBg.png");
    Texture2D astronaut = LoadTexture("../assets/images/goodJobAstronaut.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTexture(astronaut, 740, 222, RAYWHITE);

        DrawTextEx(boldPoppins, "Good job, you did really great!", Vector2(150, 114), 55, 5, WHITE);
        DrawTextEx(Poppins, "Press Space to return home", Vector2(150, 470), 40, 5, GRAY);

        ClearBackground(RAYWHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_SPACE))
        {
            spaceShip();
            break;
        }
    }
    
}