#include "gameQuiz.h"
#include <iostream>

void gameQuiz(std::string userNameStr, bool girlVoice, bool boyVoice)
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Vector2 position = { 150, 300 };
    Vector2 velocity = { 200, 0};

    bool answer1Clicked = false;
    bool answer2Clicked = false;
    bool answer3Clicked = false;

    int wrongCounter = 0;

    Texture2D background = LoadTexture("../assets/images/gameQuiz.png");
    Texture2D blackHole = LoadTexture("../assets/images/blackHole.png");
    Texture2D spaceShip = LoadTexture("../assets/images/rocket.png");

    const char* questions[8] = { "What is dark matter?",
    "How do black holes form?", "What role do magnetic\nfields play in shaping\ncelestial bodies in space?",
    "How do astronomers detect\nand study exoplanets?", "What is cosmic microwave\nbackground radiation?",
    "How do gravitational\nwaves offer new insights\ninto astronomical phenomena?",
    "What is dark energy?", "How do phenomena like\nsupernovas impact the\ncomposition of galaxies\nand the formation of elements?"
    };

    const char* rightAnswers[8] = { "Invisible, mysterious mass.", "Star collapse, supernova.",
    "Guidance, alignment, protection.", "Observation, instruments, analysis.", "Ancient light echo.",
    "Space-time ripples, observations.", "Unknown cosmic force.", "Heavy element production."
    };

    const char* wrongAnswers1[8] = { "Cosmic invisible shadows.", "Galactic phantom substance.",
    "Cosmic doughnuts emerge.", "Stellar confetti formation.", "Celestial body puppetry.", "Galactic hairdressers' influence.",
    "Psychic star-gazing.", "Tea leag reading."
    };

    const char* wrongAnswers2[8] = {
        "Galactic disco glow.", "Microwave oven residue.", "Alien dance signals.",
        "Celestial taco waves.", "Galactic happiness field.", "Cosmic rainbow essence.",
        "Celestial spice mixing.", "Galactic confetti party."
    };

    int num = GetRandomValue(0, 2);
    int questionCounter = 0;
    
    bool moveOnce = true;
    Vector2 targetPosition = {400, 400};

    Rectangle answer1 = { 270, 600, 830, 50 };
    Rectangle answer2 = { 270, 700, 830, 50 };
    Rectangle answer3 = { 270, 800, 830, 50 };

    Color Purple = { 52, 34, 69, 1500 };

    SetTextLineSpacing(45);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(blackHole, 900, 50, RAYWHITE);
        DrawTexture(spaceShip, position.x, 250, RAYWHITE);

        int textWidthQ = MeasureText(questions[questionCounter], 50);
        int xPosQ = (1440 - textWidthQ) / 2;

        int textWidthR = MeasureText(rightAnswers[questionCounter], 50);
        int xPosR = (1440 - textWidthR) / 2;

        int textWidthW1 = MeasureText(wrongAnswers1[questionCounter], 50);
        int xPosW1 = (1440 - textWidthW1) / 2;

        int textWidthW2 = MeasureText(wrongAnswers2[questionCounter], 50);
        int xPosW2 = (1440 - textWidthW2) / 2;

        
        DrawTextEx(boldPoppins, questions[questionCounter], Vector2(xPosQ, 50), 50, 5, WHITE);
        DrawRectangleRec(answer1, Purple);
        DrawRectangleRec(answer2, Purple);
        DrawRectangleRec(answer3, Purple);

        if (num == 0)
        {
            DrawTextEx(boldPoppins, rightAnswers[questionCounter], Vector2(xPosR, 600), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers1[questionCounter], Vector2(xPosW1, 700), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers2[questionCounter], Vector2(xPosW2, 800), 50, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                position.x += velocity.x;
            if ((velocity.x > 0 && position.x > targetPosition.x) || (velocity.x < 0 && position.x < targetPosition.x)) {
                moveOnce = false;
                wrongCounter += 1; 
            }  

            }
               
                   
        }

        if (num == 1)
        {
            DrawTextEx(boldPoppins, wrongAnswers1[questionCounter], Vector2(xPosW1, 600), 50, 5, WHITE);
            DrawTextEx(boldPoppins, rightAnswers[questionCounter], Vector2(xPosR, 700), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers2[questionCounter], Vector2(xPosW2, 800), 50, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), answer1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                position.x += velocity.x;
            if ((velocity.x > 0 && position.x > targetPosition.x) || (velocity.x < 0 && position.x < targetPosition.x)) {
                moveOnce = false;
                wrongCounter += 1;
            }

            }
                
        }

        if (num == 2)
        {
            DrawTextEx(boldPoppins, wrongAnswers1[questionCounter], Vector2(xPosW1, 600), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers2[questionCounter], Vector2(xPosW2, 700), 50, 5, WHITE);
            DrawTextEx(boldPoppins, rightAnswers[questionCounter], Vector2(xPosR, 800), 50, 5, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), answer1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                position.x += velocity.x;
            if ((velocity.x > 0 && position.x > targetPosition.x) || (velocity.x < 0 && position.x < targetPosition.x)) {
                moveOnce = false;
                wrongCounter += 1;
            }

            }
                
        }

        if (answer1Clicked || answer2Clicked || answer3Clicked)
        {
            questionCounter++;
            answer1Clicked = false;
            answer2Clicked = false;
            answer3Clicked = false;
            num = GetRandomValue(0, 2);
        }

        if (CheckCollisionPointRec(GetMousePosition(), answer1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            answer1Clicked = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            answer2Clicked = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            answer3Clicked = true;
        }

        if (wrongCounter == 3)
        {
                readyForQuiz(userNameStr, girlVoice, boyVoice);
                break;
        }
        else if (questionCounter == 8) {
            endScreen(userNameStr, girlVoice, boyVoice);
        }

        EndDrawing();
    }
}