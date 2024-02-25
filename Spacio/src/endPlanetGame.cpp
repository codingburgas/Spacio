#include "endPlanetGame.h"
void endPlanetGame()
{
    Rectangle tryAgain{ 520, 500, 280, 94 };
    Rectangle quit = { 520, 650, 280, 94 };

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/pickPlanetBackground.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, RAYWHITE);
        if (wonOrLostGame == 1) {
            DrawTextEx(Poppins, "You lost! Would you like to try again?", Vector2(350, 150), 60, 2, RAYWHITE);
            DrawRectangleRec(tryAgain, GetColor(0X2C2C2Cff));
            DrawTextEx(boldPoppins, "Try Again", Vector2(570, 530), 37, 5, WHITE);

            DrawRectangleRec(quit, GetColor(0X2C2C2Cff));
            DrawTextEx(boldPoppins, "Quit", Vector2(610, 680), 37, 5, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (CheckCollisionPointRec(GetMousePosition(), tryAgain)) {
                    pickPlanet();
                    break;
                }
                if (CheckCollisionPointRec(GetMousePosition(), tryAgain)) {
                    break;
                }
            }
        }
        if (wonOrLostGame == 2) {
            DrawTextEx(Poppins, "You won! Would you like to try again?", Vector2(350, 150), 60, 2, RAYWHITE);
            DrawRectangleRec(tryAgain, GetColor(0X2C2C2Cff));
            DrawTextEx(boldPoppins, "Try Again", Vector2(570, 530), 37, 5, WHITE);

            DrawRectangleRec(quit, GetColor(0X2C2C2Cff));
            DrawTextEx(boldPoppins, "Quit", Vector2(610, 680), 37, 5, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (CheckCollisionPointRec(GetMousePosition(), tryAgain)) {
                    pickPlanet();
                    break;
                }
                if (CheckCollisionPointRec(GetMousePosition(), tryAgain)) {
                    break;
                }
            }
        }

        EndDrawing();
    }




}


