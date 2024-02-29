#include "spaceShip.h"
#include "basicData.h"

void InitSpaceShipWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);

    basicData.background = LoadTexture("../assets/images/spaceShipInterior.png");
    spaceShipData.spaceship = { 560, 120, 300, 700 };

    spaceShipData.character = { 720 - 100 / 2,
                            450 - 90 / 2,
                            (100),
                            (90) };

    spaceShipData.characterSpeed = 3;

    spaceShipData.natureLocation = { 750, 480, 100, 50 };
    spaceShipData.bosonLocation = { 560, 320, 50, 100 };
    spaceShipData.planetsLocation = { 570, 650, 50, 50 };

    spaceShipData.audio = LoadMusicStream("../assets/audios/storyline.mp3");
    basicData.voiceTime = 0.0;
    spaceShipData.player = LoadTexture("../assets/images/gameCharacterLeft.png");
}

bool loadSpaceShip = true;

void spaceShip(GameState& state)
{
    if (loadSpaceShip)
    {
        InitSpaceShipWindow();
        loadSpaceShip = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(spaceShipData.audio);
    }

    SetTextLineSpacing(30);

        if (IsMusicStreamPlaying(spaceShipData.audio) and basicData.voiceTime < 36)
        {
            UpdateMusicStream(spaceShipData.audio);
            basicData.voiceTime += GetFrameTime();
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            spaceShipData.player = LoadTexture("../assets/images/gameCharacterRight.png");
            if ((spaceShipData.character.x + spaceShipData.character.width) < (spaceShipData.spaceship.x + spaceShipData.spaceship.width))
                spaceShipData.character.x += spaceShipData.characterSpeed;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            spaceShipData.player = LoadTexture("../assets/images/gameCharacterLeft.png");
            if (spaceShipData.character.x > spaceShipData.spaceship.x)
                spaceShipData.character.x -= spaceShipData.characterSpeed;
        }

        if (IsKeyDown(KEY_DOWN) && (spaceShipData.character.y + spaceShipData.character.height) < (spaceShipData.spaceship.y + spaceShipData.spaceship.height)) {
            spaceShipData.character.y += spaceShipData.characterSpeed;
        }

        if (IsKeyDown(KEY_UP) && (spaceShipData.character.y + spaceShipData.character.height) < (spaceShipData.spaceship.y + spaceShipData.spaceship.height)) {
            spaceShipData.character.y -= spaceShipData.characterSpeed;
        }

        DrawTexture(basicData.background, 0, 0, RAYWHITE);

        DrawTexture(spaceShipData.player, (spaceShipData.character.x), (spaceShipData.character.y), WHITE);

        DrawTextEx(basicData.boldPoppins, "Press Backspace to go back!", Vector2(50, 50), 20, 5, WHITE);
        //DrawTextEx(basicData.boldPoppins, " In the vast expanse of outer space,\n two companions set out on a quest for\n discovery. Amidst the universe's\n immensity, they mapped new territories\n and witnessed wonders beyond\n imagination.\n Tragedy struck when one was lost due\n to insufficient knowledge, leaving the\n other in grief.\n  Determined to honor\n his friend's memory, the survivor\n immersed himself in the study of space,\n driven by an insatiable thirst for\n understanding. With each day, he\n delved deeper into astrophysics,\n preparing tirelessly for the\n ultimate voyage into the unknown.\n When the time came, he was ready to\n prove that their mission\n was achievable.", Vector2(920, 70), 22, 5, WHITE);

        if (CheckCollisionRecs(spaceShipData.character, spaceShipData.natureLocation))
        {
            DrawTextEx(basicData.boldPoppins, "Press E for nature!", Vector2(680, 440), 20, 5, WHITE);

            if (IsKeyDown(KEY_E))
            {
                state = GameState::NatureScript; 
            }
        }

        if (CheckCollisionRecs(spaceShipData.character, spaceShipData.bosonLocation))
        {
            DrawTextEx(basicData.boldPoppins, "Press E for higgs boson!", Vector2(550, 300), 20, 5, WHITE);

            if (IsKeyDown(KEY_E))
            {
                state = GameState::HiggsBoson; 
            }
        }

        if (CheckCollisionRecs(spaceShipData.character, spaceShipData.planetsLocation))
        {
            DrawTextEx(basicData.boldPoppins, "Press E for planets!", Vector2(550, 620), 20, 5, WHITE);

            if (IsKeyDown(KEY_E))
            {
                state = GameState::GetStation;
            }
        }


        if (IsKeyDown(KEY_BACKSPACE))
        {
            state = GameState::Intro;
        }

        DrawRectangleRec(spaceShipData.spaceship, GetColor(0x312b4700));

        DrawRectangleRec(spaceShipData.natureLocation, GetColor(0x312b4700));
        DrawRectangleRec(spaceShipData.bosonLocation, GetColor(0x312b4700));
        DrawRectangleRec(spaceShipData.planetsLocation, GetColor(0x312b4700));
}