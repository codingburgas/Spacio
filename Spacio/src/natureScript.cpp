#include "natureScript.h"
#include "basicData.h"
#include <iostream>

void InitNatureScriptWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);

    basicData.background = LoadTexture("../assets/images/natureBackground.png");

    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/natureScriptBoy.mp3");
    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/natureScriptGirl.mp3");

    basicData.voiceTime = 0.0;

    for (int i = 0; i < 8; i++) {
        natureScriptData.boyImages[i] = LoadTexture((natureScriptData.boyAstronaut[i]).c_str());
    }

    for (int i = 0; i < 8; i++) {
        natureScriptData.girlImages[i] = LoadTexture((natureScriptData.girlAstronaut[i]).c_str());
    }
}

bool loadNature = true;
int counter = 0;

void natureScript(GameState& state)
{
    if (loadNature)
    {
        InitNatureScriptWindow();
        loadNature = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

        DrawTexture(basicData.background, 0, 0, RAYWHITE);

        if (boyVoice)
        {
            DrawTexture(natureScriptData.boyImages[counter], 60, 250, WHITE);
            if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime < 67.6)
            {
                UpdateMusicStream(basicData.boyVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }
        if (girlVoice)
        {
            DrawTexture(natureScriptData.girlImages[counter], 60, 250, WHITE);
            if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime < 73)
            {
                UpdateMusicStream(basicData.girlVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }
        DrawTextEx(basicData.boldPoppins, (natureScriptData.script[counter]).c_str(), Vector2{665, 400}, 40, 5, WHITE);
        DrawTextEx(basicData.boldPoppins, "Press Enter to continue!", Vector2{ 900, 800 }, 40, 5, DARKGRAY);

        if (IsKeyPressed(KEY_ENTER))
        {
            counter++;
        }

        if (counter == 7)
        {
            state = GameState::ReadyForQuiz;
        }


}