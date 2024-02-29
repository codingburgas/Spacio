#include "gameQuiz.h"
#include <iostream>
#include "basicData.h"

void InitGameQuiz()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);

    gameQuizData.position = { 150, 300 };
    gameQuizData.velocity = { 200, 0 };

    gameQuizData.wrongCounter = 0;

    basicData.background = LoadTexture("../assets/images/gameQuiz.png");
    gameQuizData.blackHole = LoadTexture("../assets/images/blackHole.png");
    gameQuizData.spaceShip = LoadTexture("../assets/images/rocket.png");

    gameQuizData.num = GetRandomValue(0, 2);
    gameQuizData.questionCounter = 0;

    gameQuizData.targetPosition = { 400, 400 };

    gameQuizData.answerTop = { 270, 600, 830, 50 };
    gameQuizData.answerMiddle = { 270, 700, 830, 50 };
    gameQuizData.answerBottom = { 270, 800, 830, 50 };

    gameQuizData.Purple = { 52, 34, 69, 150 };

    basicData.voiceTime = 0.0;
    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/gameBoy.mp3");
    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/gameGirl.mp3");


}

bool loadGameQuiz = true;

void gameQuiz(GameState& state)
{
    if (loadGameQuiz)
    {
        InitGameQuiz();
        loadGameQuiz = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

    SetTextLineSpacing(45);

        if (boyVoice)
        {
            if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime < 2.3)
            {
                UpdateMusicStream(basicData.boyVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }

        if (girlVoice)
        {
            if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime < 2.3)
            {
                UpdateMusicStream(basicData.girlVoiceAudio);
                basicData.voiceTime += GetFrameTime();
            }
        }

        ClearBackground(RAYWHITE);

        DrawTexture(basicData.background, 0, 0, RAYWHITE);

        DrawTexture(gameQuizData.blackHole, 900, 50, RAYWHITE);
        DrawTexture(gameQuizData.spaceShip, gameQuizData.position.x, 250, RAYWHITE);

        int textWidthQ = MeasureText(gameQuizData.questions[gameQuizData.questionCounter].c_str(), 50);
        int xPosQ = (1440 - textWidthQ) / 2;

        int textWidthR = MeasureText(gameQuizData.rightAnswers[gameQuizData.questionCounter].c_str(), 50);
        int xPosR = (1440 - textWidthR) / 2;

        int textWidthW1 = MeasureText(gameQuizData.wrongAnswersBottom[gameQuizData.questionCounter].c_str(), 50);
        int xPosW1 = (1440 - textWidthW1) / 2;

        int textWidthW2 = MeasureText(gameQuizData.wrongAnswersMiddle[gameQuizData.questionCounter].c_str(), 50);
        int xPosW2 = (1440 - textWidthW2) / 2;

        
        DrawTextEx(basicData.boldPoppins, (gameQuizData.questions[gameQuizData.questionCounter]).c_str(), Vector2(xPosQ, 50), 50, 5, WHITE);
        DrawRectangleRec(gameQuizData.answerTop, gameQuizData.Purple);
        DrawRectangleRec(gameQuizData.answerMiddle, gameQuizData.Purple);
        DrawRectangleRec(gameQuizData.answerBottom, gameQuizData.Purple);

        if (gameQuizData.num == 0)
        {
            DrawTextEx(basicData.boldPoppins, (gameQuizData.rightAnswers[gameQuizData.questionCounter]).c_str(), Vector2(xPosR, 600), 50, 5, WHITE);
            DrawTextEx(basicData.boldPoppins, (gameQuizData.wrongAnswersBottom[gameQuizData.questionCounter]).c_str(), Vector2(xPosW1, 700), 50, 5, WHITE);
            DrawTextEx(basicData.boldPoppins, (gameQuizData.wrongAnswersMiddle[gameQuizData.questionCounter]).c_str(), Vector2(xPosW2, 800), 50, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerMiddle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerBottom) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                gameQuizData.position.x += gameQuizData.velocity.x;
            if ((gameQuizData.velocity.x > 0 && gameQuizData.position.x > gameQuizData.targetPosition.x) || (gameQuizData.velocity.x < 0 && gameQuizData.position.x < gameQuizData.targetPosition.x)) {
                gameQuizData.moveOnce = false;
                gameQuizData.wrongCounter += 1;
            }  

            }
               
                   
        }

        if (gameQuizData.num == 1)
        {
            DrawTextEx(basicData.boldPoppins, (gameQuizData.wrongAnswersBottom[gameQuizData.questionCounter]).c_str(), Vector2(xPosW1, 600), 50, 5, WHITE);
            DrawTextEx(basicData.boldPoppins, (gameQuizData.rightAnswers[gameQuizData.questionCounter]).c_str(), Vector2(xPosR, 700), 50, 5, WHITE);
            DrawTextEx(basicData.boldPoppins, (gameQuizData.wrongAnswersMiddle[gameQuizData.questionCounter]).c_str(), Vector2(xPosW2, 800), 50, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerTop) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerBottom) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                gameQuizData.position.x += gameQuizData.velocity.x;
            if ((gameQuizData.velocity.x > 0 && gameQuizData.position.x > gameQuizData.targetPosition.x) || (gameQuizData.velocity.x < 0 && gameQuizData.position.x < gameQuizData.targetPosition.x)) {
                gameQuizData.moveOnce = false;
                gameQuizData.wrongCounter += 1;
            }

            }
                
        }

        if (gameQuizData.num == 2)
        {
            DrawTextEx(basicData.boldPoppins, (gameQuizData.wrongAnswersBottom[gameQuizData.questionCounter]).c_str(), Vector2(xPosW1, 600), 50, 5, WHITE);
            DrawTextEx(basicData.boldPoppins, (gameQuizData.wrongAnswersMiddle[gameQuizData.questionCounter]).c_str(), Vector2(xPosW2, 700), 50, 5, WHITE);
            DrawTextEx(basicData.boldPoppins, (gameQuizData.rightAnswers[gameQuizData.questionCounter]).c_str(), Vector2(xPosR, 800), 50, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerTop) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerMiddle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                gameQuizData.position.x += gameQuizData.velocity.x;
            if ((gameQuizData.velocity.x > 0 && gameQuizData.position.x > gameQuizData.targetPosition.x) || (gameQuizData.velocity.x < 0 && gameQuizData.position.x < gameQuizData.targetPosition.x)) {
                gameQuizData.moveOnce = false;
                gameQuizData.wrongCounter += 1;
            }

            }
                
        }

        if (gameQuizData.answerTopClicked || gameQuizData.answerMiddleClicked || gameQuizData.answerBottomClicked)
        {
            gameQuizData.questionCounter++;
            gameQuizData.answerTopClicked = false;
            gameQuizData.answerMiddleClicked = false;
            gameQuizData.answerBottomClicked = false;
            gameQuizData.num = GetRandomValue(0, 2);
        }

        if (CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerTop) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            gameQuizData.answerTopClicked = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerMiddle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            gameQuizData.answerMiddleClicked = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), gameQuizData.answerBottom) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            gameQuizData.answerBottomClicked = true;
        }

        if (gameQuizData.wrongCounter == 3)
        {
            state = GameState::NatureScript;
            loadGameQuiz = true;
            return;
        }
        else if (gameQuizData.questionCounter == 7)
        {
            state = GameState::EndScreen;
            return;
        }
}