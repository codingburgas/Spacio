#include "spaceShip.h"


void spaceShip(std::string userNameStr)
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/spaceShipInterior.png");

    Rectangle spaceship(560, 120, 300, 700);

    Rectangle character = { 720 - 100 / 2,
                            450 - 90 / 2,
                            (100),
                            (90) };

    float characterSpeed = 3;

    Rectangle natureLocation = { 750, 480, 100, 50 };
    Rectangle bosonLocation = { 560, 320, 50, 100 };
    Rectangle planetsLocation = { 570, 650, 50, 50 };

    Texture2D player = LoadTexture("../assets/images/gameCharacter.png");

    while (!WindowShouldClose())
    {


        if (IsKeyDown(KEY_RIGHT))
        {
            player = LoadTexture("../assets/images/gameCharacterRotated.png");
            if ((character.x + character.width) < (spaceship.x + spaceship.width))
                character.x += characterSpeed;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            player = LoadTexture("../assets/images/gameCharacter.png");
            if (character.x > spaceship.x)
                character.x -= characterSpeed;
        }

        if (IsKeyDown(KEY_DOWN) && (character.y + character.height) < (spaceship.y + spaceship.height)) {
            character.y += characterSpeed;
        }

        if (IsKeyDown(KEY_UP) && (character.y + character.height) < (spaceship.y + spaceship.height)){
            character.y -= characterSpeed;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(player, (character.x), (character.y), WHITE);

        DrawTextEx(boldPoppins, "Press Backspace to go back!", Vector2(50, 50), 20, 5, WHITE);

        if (CheckCollisionRecs(character, natureLocation))
        {
            DrawTextEx(boldPoppins, "Press E for nature!", Vector2(680, 440), 20, 5, WHITE);
        }

        if (CheckCollisionRecs(character, natureLocation) && IsKeyDown(KEY_E))
        {
            natureScript(userNameStr);
            break;
        }

        if (CheckCollisionRecs(character, bosonLocation))
        {
            DrawTextEx(boldPoppins, "Press E for higgs boson!", Vector2(550, 300), 20, 5, WHITE);
        }

        if (CheckCollisionRecs(character, bosonLocation) && IsKeyDown(KEY_E))
        {

            particlePick(userNameStr);
            break;
        }

        if (CheckCollisionRecs(character, planetsLocation))
        {
            DrawTextEx(boldPoppins, "Press E for planets!", Vector2(550, 620), 20, 5, WHITE);
        }

        if (CheckCollisionRecs(character, planetsLocation) && IsKeyDown(KEY_E))
        {
            getStation(userNameStr);
            break;
        }

        if (IsKeyDown(KEY_BACKSPACE))
        {
            intro();
        }

        DrawRectangleRec(spaceship, GetColor(0x312b4700));

        DrawRectangleRec(natureLocation, GetColor(0x312b4700));
        DrawRectangleRec(bosonLocation, GetColor(0x312b4700));
        DrawRectangleRec(planetsLocation, GetColor(0x312b4700));

        EndDrawing();
    }
}