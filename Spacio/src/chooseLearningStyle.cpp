#include "chooseLearningStyle.h"
#include "characterPick.h"
#include "mainMenu.h"
#include "intro.h"
#include "basicData.h"
#include <iostream>

//Check if cursor is on rectangle

bool cursorOnRectangle(Rectangle rectangle) {
    if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
        return true;
    }

    return false;
}
// Set mouse cursor based on collision

void mouseCursorLearningStyle(Rectangle reading, Rectangle playing)
{
    if (CheckCollisionPointRec(GetMousePosition(), reading)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), playing)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

void InitCLSWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 200, NULL, NULL);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 200, NULL, NULL);

    basicData.background = LoadTexture("../assets/images/chooseLearningStyleBg.png");

    chooseLearningStyleData.reading = { 283, 302, 295, 295 };
    chooseLearningStyleData.playing = { 830,304 ,295 ,295 };

    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/learningStyleFemale.mp3");
    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/learningStyleMale.mp3");

    basicData.voiceTime = 0.0;
}

bool loadCLS = true;

void chooseLearningStyle(GameState& state) {
    if (loadCLS)
    {
        InitCLSWindow();
        loadCLS = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

    if (girlVoice)
    {
        if (basicData.voiceTime < 4.2)
        {
            UpdateMusicStream(basicData.girlVoiceAudio); // Update music
            basicData.voiceTime += GetFrameTime();
        }
    }
    else if (boyVoice)
    {
        if (basicData.voiceTime < 3.2)
        {
            PlayMusicStream(basicData.boyVoiceAudio);
            UpdateMusicStream(basicData.boyVoiceAudio); // Update music
            basicData.voiceTime += GetFrameTime();
        }
    }

    DrawTexture(basicData.background, 0, 0, RAYWHITE);

    DrawTextEx(basicData.boldPoppins, "How do you want to learn?", Vector2(336, 137), 64, 5, WHITE);
    DrawTextEx(basicData.boldPoppins, "By reading", Vector2(371, 605), 32, 5, WHITE);
    DrawTextEx(basicData.boldPoppins, "By playing", Vector2(909, 605), 32, 5, WHITE);

    mouseCursorLearningStyle(chooseLearningStyleData.reading, chooseLearningStyleData.playing);

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (cursorOnRectangle(chooseLearningStyleData.reading)) {
            state = GameState::Questions;
        }
        if (cursorOnRectangle(chooseLearningStyleData.playing)) {
            state = GameState::SpaceShip;
        }
    }

}
