#include "planetGame.h"


void planetGame() {



    Texture2D background = LoadTexture("../assets/images/pickPlanetBackground.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        switch (chosenPlanetIndex) {
        case 0:
            DrawText("You chose the Sun.", 100, 100, 20, BLACK);
            break;
        case 1:
            DrawText("You chose Mercury.", 100, 100, 20, BLACK);
            break;
        case 2:
            DrawText("You chose Venus.", 100, 100, 20, BLACK);
            break;
        case 3:
            DrawText("You chose Earth.", 100, 100, 20, BLACK);
            break;
        case 4:
            DrawText("You chose Mars.", 100, 100, 20, BLACK);
            break;
        case 5:
            DrawText("You chose Jupiter.", 100, 100, 20, BLACK);
            break;
        case 6:
            DrawText("You chose Saturn.", 100, 100, 20, BLACK);
            break;
        case 7:
            DrawText("You chose Uranus.", 100, 100, 20, BLACK);
            break;
        case 8:
            DrawText("You chose Neptune.", 100, 100, 20, BLACK);
            break;
        default:
            DrawText("No planet chosen.", 100, 100, 20, BLACK);
            break;
        }

       EndDrawing();
    }


}