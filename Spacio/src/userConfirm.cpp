#include "userConfirm.h"
#include "characterPick.h"
#include "questions.h"
#include "mainMenu.h"
#include "basicData.h"
#include <iostream>

void InitUserConfirmWindow()
{
    basicData.background = LoadTexture("../assets/images/userConfirmBackground.png");
    basicData.girlCompanion = LoadTexture("../assets/images/girlAstronautSure.png");
    basicData.boyCompanion = LoadTexture("../assets/images/boyAstronautSure.png");

    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);

    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/userConfirmGirl.mp3");
    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/userConfirmBoy.mp3");
    basicData.voiceTime = 0.0;
}

bool loadUC = true;
std::string choice;

void userConfirm(GameState& state)
{
    if (loadUC)
    {
        InitUserConfirmWindow();
        loadUC = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

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

        DrawTexture(basicData.background, 0, 0, RAYWHITE);

        if (girlVoice)
        {
            DrawTexture(basicData.girlCompanion, 50, 250, RAYWHITE);
            PlayMusicStream(basicData.girlVoiceAudio);
            if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime < 17)
            {
                UpdateMusicStream(basicData.girlVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }
        else if (boyVoice)
        {
            DrawTexture(basicData.boyCompanion, 50, 250, RAYWHITE);
            PlayMusicStream(basicData.boyVoiceAudio);
            if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime < 13)
            {
                UpdateMusicStream(basicData.boyVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }
        DrawTextEx(basicData.boldPoppins, ("It seems like you're interested in " + choice + "\nWould you like to change the subject?").c_str(), Vector2(400, 120), 50, 3, RAYWHITE);

        DrawTextEx(basicData.Poppins, "Press Enter to continue\n\nPress 1 to learn about Planets\nPress 2 for Higgs Boson\nPress 3 for Nature", Vector2(675, 420), 50, 3, GetColor(0xBABABAff));

        if (IsKeyPressed(KEY_ENTER))
        {
            if (pick == 1) state = GameState::GetStation;
            else if (pick == 2) state = GameState::ParticlePick;
            else if (pick == 3) state = GameState::NatureScript;
        }
        else if (IsKeyPressed(KEY_ONE))
        {
            state = GameState::GetStation;
        }
        else if (IsKeyPressed(KEY_TWO))
        {
            state = GameState::ParticlePick;
        }
        else if (IsKeyPressed(KEY_THREE))
        {
            state = GameState::NatureScript;
        }
}