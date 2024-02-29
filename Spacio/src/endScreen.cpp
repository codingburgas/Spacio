#include "endScreen.h"
#include "basicData.h"
#include "userName.h"
#include <iostream>

void InitEndScreen()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    basicData.background = LoadTexture("../assets/images/endScreenBg.png");
    basicData.boyCompanion = LoadTexture("../assets/images/goodJobAstronaut.png");
    basicData.girlCompanion = LoadTexture("../assets/images/goodJobGirlAstronaut.png");

    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/greatJobFemale.mp3");
    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/greatJobMale.mp3");

    basicData.voiceTime = 0.0;
}

bool loadEndScreen = true;

void endScreen(GameState& state) {
    DrawTexture(basicData.background, 0, 0, RAYWHITE);
    if (loadEndScreen)
    {
        InitEndScreen();
        loadEndScreen = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
        ClearBackground(RAYWHITE);
    }

    // Play music streams based on chosen character
    if (girlVoice)
    {
        PlayMusicStream(basicData.girlVoiceAudio);
        if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime <= 2.7)
        {
            UpdateMusicStream(basicData.girlVoiceAudio);
            basicData.voiceTime += GetFrameTime();
        }
    }
    else if (boyVoice)
    {
        PlayMusicStream(basicData.boyVoiceAudio);
        if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime <= 2.5)
        {
            UpdateMusicStream(basicData.boyVoiceAudio);
            basicData.voiceTime += GetFrameTime();
        }
    }

    // Draw textures and text
    if (boyVoice) DrawTexture(basicData.boyCompanion, 740, 222, RAYWHITE);
    if (girlVoice) DrawTexture(basicData.girlCompanion, 740, 222, RAYWHITE);

    std::string message = "Good job " + name + ", you did really great!";
    DrawTextEx(basicData.boldPoppins, message.c_str(), Vector2(150, 114), 55, 5, WHITE);
    DrawTextEx(basicData.Poppins, "Press Space to return home", Vector2(150, 470), 40, 5, GRAY);

    // Check for space key press to continue
    if (IsKeyPressed(KEY_SPACE))
    {
        state = GameState::Intro;
    }
}