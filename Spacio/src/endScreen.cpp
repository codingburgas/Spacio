#include "endScreen.h"

void endScreen(std::string userNameStr, bool girlVoice, bool boyVoice) {
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/endScreenBg.png");
    Texture2D boyAstronaut = LoadTexture("../assets/images/goodJobAstronaut.png");
    Texture2D girlAstronaut = LoadTexture("../assets/images/goodJobGirlAstronaut.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();

        DrawTexture(background, 0, 0, RAYWHITE);
        if(boyVoice) DrawTexture(boyAstronaut, 740, 222, RAYWHITE);
        if(girlVoice) DrawTexture(girlAstronaut, 740, 222, RAYWHITE);

        DrawTextEx(boldPoppins, "Good job, you did really great!", Vector2(150, 114), 55, 5, WHITE);
        DrawTextEx(Poppins, "Press Space to return home", Vector2(150, 470), 40, 5, GRAY);

        ClearBackground(RAYWHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_SPACE))
        {
            spaceShip(userNameStr, girlVoice, boyVoice);
            break;
        }
    }
    
}