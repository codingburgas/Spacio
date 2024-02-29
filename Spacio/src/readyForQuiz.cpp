#include "readyForQuiz.h"
#include "basicData.h"

int pick;

void Cursor(Rectangle buttonYes, Rectangle buttonNo)
{
    if (CheckCollisionPointRec(GetMousePosition(), buttonYes)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else SetMouseCursor(MOUSE_CURSOR_ARROW);

    if (CheckCollisionPointRec(GetMousePosition(), buttonNo)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
}

void InitRFQWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);

    basicData.background = LoadTexture("../assets/images/readyBackground.png");
    basicData.girlCompanion = LoadTexture("../assets/images/readyForQuizGirlAstronaut.png");
    basicData.boyCompanion = LoadTexture("../assets/images/astronaut.png");

    readyForQuizData.buttonYes = { 850, 170, 300, 300 };
    readyForQuizData.buttonNo = { 850, 500, 300, 300 };

    readyForQuizData.starYes = LoadTexture("../assets/images/starYes.png");
    readyForQuizData.starNo = LoadTexture("../assets/images/starNo.png");

    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/readyMale.mp3");
    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/readyFemale.mp3");
}

bool loadRFQ = true;

void readyForQuiz(GameState& state)
{
    if (loadRFQ)
    {
        InitRFQWindow();
        loadRFQ = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

    if (boyVoice)
    {
        if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime < 1.4)
        {
            UpdateMusicStream(basicData.boyVoiceAudio);
            basicData.voiceTime += GetFrameTime();
        }
    }

    if (girlVoice)
    {
        if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime < 1.8)
        {
            UpdateMusicStream(basicData.girlVoiceAudio);
            basicData.voiceTime += GetFrameTime();
        }
    }

    ClearBackground(RAYWHITE);

    DrawTexture(basicData.background, 0, 0, RAYWHITE);

    DrawTextEx(basicData.boldPoppins, "Are you ready for a quiz?", Vector2(450, 50), 50, 5, WHITE);

    if (boyVoice) DrawTexture(basicData.boyCompanion, 50, 250, RAYWHITE);
    if (girlVoice) DrawTexture(basicData.girlCompanion, 50, 250, RAYWHITE);

    DrawTexture(readyForQuizData.starYes, 800, 150, RAYWHITE);
    DrawTexture(readyForQuizData.starNo, 800, 450, RAYWHITE);

    DrawRectangleRec(readyForQuizData.buttonYes, GetColor(0x312b4700));
    DrawRectangleRec(readyForQuizData.buttonNo, GetColor(0x312b4700));

    Cursor(readyForQuizData.buttonYes, readyForQuizData.buttonNo);

    if (CheckCollisionPointRec(GetMousePosition(), readyForQuizData.buttonYes) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        state = GameState::GameQuiz;
    }
    else if (CheckCollisionPointRec(GetMousePosition(), readyForQuizData.buttonNo) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        /*spaceShip(userNameStr, girlVoice, boyVoice);
        break;*/
    }

}