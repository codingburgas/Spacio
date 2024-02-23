#include "spaceShip.h"
    
    std::string userNameStr;

    void spaceShip()
    {
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/spaceShipInterior.png");

    Rectangle spaceship(560, 120, 300, 700);

    Texture2D player = LoadTexture("../assets/images/gameCharacter.png");

    Rectangle character = { 720 - player.width / 2,
                            450 - player.height / 2,
                            (player.width),
                            (player.height) };

    float characterSpeed = 2;

    Rectangle place1 = { 750, 480, 100, 50 };
    Rectangle place2 = { 560, 320, 50, 100 };
    Rectangle place3 = { 570, 650, 50, 50 };

    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_RIGHT) && (character.x + character.width) < (spaceship.x + spaceship.width))
            character.x += characterSpeed;

        if (IsKeyDown(KEY_LEFT) && character.x > spaceship.x)
            character.x -= characterSpeed;

        if (IsKeyDown(KEY_DOWN) && (character.y + character.height) < (spaceship.y + spaceship.height))
            character.y += characterSpeed;

        if (IsKeyDown(KEY_UP) && character.y > spaceship.y)
            character.y -= characterSpeed;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(player, (character.x), (character.y), WHITE);

        if (CheckCollisionRecs(character, place1))
        {
            DrawTextEx(boldPoppins, "Press E to enter!", Vector2(680, 440), 20, 5, BLACK);
        }

        if (CheckCollisionRecs(character, place1) && IsKeyDown(KEY_E)) {
            
            natureScript();
        }

        if (CheckCollisionRecs(character, place2))
        {
            DrawTextEx(boldPoppins, "Press E to enter!", Vector2(550, 300), 20, 5, BLACK);
        }

        if (CheckCollisionRecs(character, place2) && IsKeyDown(KEY_E)) {

            particlePick(userNameStr);
        }

        if (CheckCollisionRecs(character, place3))
        {
            DrawTextEx(boldPoppins, "Press E to enter!", Vector2(550, 620), 20, 5, BLACK);
        }

        if (CheckCollisionRecs(character, place3) && IsKeyDown(KEY_E)) {

            getStation();
        }

        DrawRectangleRec(spaceship, GetColor(0x312b4700));
        DrawRectangleRec(place1, GetColor(0x312b4700));
        DrawRectangleRec(place2, GetColor(0x312b4700));
        DrawRectangleRec(place3, GetColor(0x312b4700));

        EndDrawing();
    }
    }
