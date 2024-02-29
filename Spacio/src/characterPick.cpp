#include "characterPick.h"
#include "mainMenu.h"
#include "basicData.h"
#include <iostream>

void mouseCursorAstronauts(Rectangle boyAstronaut, Rectangle girlAstronaut)
{
    if (CheckCollisionPointRec(GetMousePosition(), boyAstronaut)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), girlAstronaut)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

bool boyVoice = false;
bool girlVoice = false;

bool pickVoice(Rectangle boyBox, Rectangle girlBox)
{

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(GetMousePosition(), boyBox)) {
            boyVoice = true;
        }
        if (CheckCollisionPointRec(GetMousePosition(), girlBox)) {
            girlVoice = true;
        }
    }

    return girlVoice || boyVoice;
}

void InitCharacterPick()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 200, 0, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 200, 0, 0);
    characterPickData.backgroundCharacter = LoadTexture("../assets/images/characterPickBackground.png");

    characterPickData.boyAstronautImg = LoadTexture("../assets/images/boyAstronaut.png");
    characterPickData.girlAstronautImg = LoadTexture("../assets/images/girlAstronaut.png");

    characterPickData.boyBox = { 285, 200, 161, 204 };
    characterPickData.girlBox = { 1018, 180, 214, 214 };

    characterPickData.characterPickAudio = LoadMusicStream("../assets/audios/characterPick.mp3");
    characterPickData.audioSecondCharacter = 0.0;
}

bool loadCP = true;

void characterPick(GameState& state)
{
    if (loadCP)
    {
        InitCharacterPick();
        loadCP = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(characterPickData.characterPickAudio);
    }
    if (IsMusicStreamPlaying(characterPickData.characterPickAudio) and characterPickData.audioSecondCharacter < 1.3)
            {
                UpdateMusicStream(characterPickData.characterPickAudio);
                characterPickData.audioSecondCharacter += GetFrameTime();
            }

            DrawTexture(characterPickData.backgroundCharacter, 0, 0, RAYWHITE);

            DrawTexture(characterPickData.girlAstronautImg, 1018, 180, RAYWHITE);
            DrawTexture(characterPickData.boyAstronautImg, 285, 200, RAYWHITE);

            mouseCursorAstronauts(characterPickData.boyBox, characterPickData.girlBox);

            DrawTextEx(basicData.boldPoppins, "Choose a companion", Vector2(350, 60), 75, 5, WHITE);
            pickVoice(characterPickData.boyBox, characterPickData.girlBox);

            if (boyVoice)
            {
                state = GameState::ChooseLearningStyle;
            }

            if (girlVoice)
            {
                state = GameState::ChooseLearningStyle;
            }
}