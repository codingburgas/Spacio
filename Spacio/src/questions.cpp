#include "questions.h"
#include "characterPick.h"
#include "mainMenu.h"
#include "basicData.h"
#include "intro.h"
#include <iostream>

void mouseCursorQuestions(Rectangle planetButton, Rectangle higgsButton)
{
    if (CheckCollisionPointRec(GetMousePosition(), planetButton)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), higgsButton)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

void confirmReady(int higgs, int planets) {
    if (planets > higgs)
    {
        pick = 1;
    }
    else if (higgs > planets)
    {
        pick = 2;
    }
    else if (higgs == planets)
    {
        pick = 3;
    }
}

void InitQuestionsWindow()
{
    basicData.background = LoadTexture("../assets/images/questionsBackground.png");
    basicData.boyCompanion = LoadTexture("../assets/images/boyCompanion.png");
    basicData.girlCompanion = LoadTexture("../assets/images/girlCompanion.png");

    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 200, NULL, NULL);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 200, NULL, NULL);

    questionData.planetButton = { 648, 500, 150, 40 };
    questionData.higgsButton = { 648, 580, 180, 40 };
    questionData.buttonClickedPlanets = false;
    questionData.buttonClickedHiggs = false;

    questionData.questionCounter = 0;
    questionData.planets = 0;
    questionData.higgs = 0;

    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/welcomeAudio.mp3");
    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/welcomeAudioGirl.mp3");

    basicData.voiceTime = 0.0;
}

bool loadQuestions = true;

void questions(GameState& state)
{

    if (loadQuestions)
    {
        InitQuestionsWindow();
        loadQuestions = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

    SetTextLineSpacing(38);

        if (CheckCollisionPointRec(GetMousePosition(), questionData.planetButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            questionData.buttonClickedPlanets = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), questionData.higgsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            questionData.buttonClickedHiggs = true;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(basicData.background, 0, 0, RAYWHITE);

        if (boyVoice)
        {
            DrawTexture(basicData.boyCompanion, 50, 250, RAYWHITE);
            PlayMusicStream(basicData.boyVoiceAudio);
            if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime < 2.6)
            {
                UpdateMusicStream(basicData.boyVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }

        if (girlVoice)
        {
            DrawTexture(basicData.girlCompanion, 50, 250, RAYWHITE);
            PlayMusicStream(basicData.girlVoiceAudio);
            if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime < 2.2)
            {
                UpdateMusicStream(basicData.girlVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }

        DrawTextEx(basicData.boldPoppins, "Welcome, choose what you want to learn about", Vector2{ 250, 160 }, 50, 5, WHITE);

        DrawTextEx(basicData.Poppins, (questionData.questions[questionData.questionCounter]).c_str(), Vector2{600, 320}, 40, 5, WHITE);

        DrawRectangleRec(questionData.planetButton, GetColor(0x312b4700));
        DrawTextEx(basicData.boldPoppins, (questionData.planetsAnswers[questionData.questionCounter]).c_str(), Vector2{665, 500}, 40, 5, WHITE);

        mouseCursorQuestions(questionData.planetButton, questionData.higgsButton);

        DrawRectangleRec(questionData.higgsButton, GetColor(0x312b4700));
        DrawTextEx(basicData.boldPoppins, (questionData.higgsAnswers[questionData.questionCounter]).c_str(), Vector2{665, 580}, 40, 5, WHITE);



        if (questionData.buttonClickedPlanets)
        {
            questionData.planets++;
            questionData.questionCounter++;
            questionData.buttonClickedPlanets = false;
        }

        if (questionData.buttonClickedHiggs)
        {
            questionData.higgs++;
            questionData.questionCounter++;
            questionData.buttonClickedHiggs = false;
        }
        confirmReady(questionData.higgs, questionData.planets);
        if (questionData.questionCounter >= 8)
        {
            state = GameState::UserConfirm;
        }

    }
