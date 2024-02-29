#include "getStation.h"
#include "userName.h"
#include "characterPick.h"
#include "mainMenu.h"
#include "basicData.h"
#include <iostream>

void InitGetStationWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);
    
    basicData.background = LoadTexture("../assets/images/getStationBackground.png");
    
    userNameData.inputBox = { 320, 420, 860, 120 };
    userNameData.maxChars = 15;
    userNameData.letterCount = 0;
    userNameData.framesCounter = 0;

    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/getStationFemale.mp3");
    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/getStationMale.mp3");
    basicData.voiceTime = 0.0;
}

bool loadGetStation = true;

void getStation(GameState& state) {

    if (loadGetStation)
    {
        InitGetStationWindow();
        loadGetStation = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

    if (CheckCollisionPointRec(GetMousePosition(), userNameData.inputBox))
    {
        userNameData.mouseOnText = true;
    }
    else
    {
        userNameData.mouseOnText = false;
    }

    if (userNameData.mouseOnText) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && (userNameData.station.length() < userNameData.maxChars)) {
                userNameData.station += (char)key;
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (!userNameData.station.empty()) {
                userNameData.station.pop_back();
            }
        }
    }

        if (girlVoice)
        {
            PlayMusicStream(basicData.girlVoiceAudio);
            if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime <= 2.1)
            {
                UpdateMusicStream(basicData.girlVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }
        else if (boyVoice)
        {
            PlayMusicStream(basicData.boyVoiceAudio);
            if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime <= 2.1)
            {
                UpdateMusicStream(basicData.boyVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }

        DrawTexture(basicData.background, 0, 0, RAYWHITE);
        DrawTextEx(basicData.boldPoppins, "Which station are you launching from?", Vector2{ 280, 260 }, 50, 5, WHITE);


        DrawRectangleRec(userNameData.inputBox, GetColor(0x332244ff));
        if (userNameData.mouseOnText) DrawRectangleLines(userNameData.inputBox.x, userNameData.inputBox.y, userNameData.inputBox.width, userNameData.inputBox.height, PURPLE);
        else DrawRectangleLines(userNameData.inputBox.x, userNameData.inputBox.y, userNameData.inputBox.width, userNameData.inputBox.height, DARKGRAY);

        int textWidth = MeasureText((userNameData.station).c_str(), 100);
        int textX = userNameData.inputBox.x + (userNameData.inputBox.width - textWidth) / 2;
        int textY = userNameData.inputBox.y + (userNameData.inputBox.height - 100) / 2;

        DrawTextEx(basicData.boldPoppins, (userNameData.station).c_str(), Vector2(textX, textY), 100, 5, RAYWHITE);

        DrawTextEx(basicData.boldPoppins, "Press Enter to continue", Vector2{ 480, 660 }, 50, 5, WHITE);

        if (IsKeyPressed(KEY_ENTER))
        {
            state = GameState::PickPlanet;
        }
    }