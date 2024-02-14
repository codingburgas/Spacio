#include "userConfirm.h"
#include <iostream>

void userConfirm(int pick)
{
    Texture2D background = LoadTexture("../assets/images/userConfirmBackground.png");
    std::string choice;

    Font poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    if (pick == 1)
    {
        choice = "astronomy";
    }
    else if (pick == 2)
    {
        choice = "astrophysics";
    }
    else if (pick == 3)
    {
        choice = "nature";
    }

    SetTextLineSpacing(45);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTextEx(boldPoppins, ("It seems like you're interested in " + choice + "\nWould you like to change the subject?").c_str(), Vector2(400, 120), 50, 3, RAYWHITE);

        DrawTextEx(poppins, "Press Enter to continue\n\nPress 1 to learn about Planets\nPress 2 for Higgs Boson\nPress 3 for Nature", Vector2(675, 420), 50, 3, GetColor(0xBABABAff));

        if (IsKeyPressed(KEY_ENTER))
        {
            break;
        }
        else if (IsKeyPressed(KEY_ONE))
        {
            getStation();
            break;
        }
        else if (IsKeyPressed(KEY_TWO))
        {

            break;
        }

        EndDrawing();
    }

}
