#include "gameQuiz.h"
#include <iostream>

void gameQuiz()
{
	Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
	Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Rectangle answer1 = { 500, 600, 400, 50 };
    Rectangle answer2 = { 500, 700, 400, 50 };
    Rectangle answer3 = { 500, 800, 400, 50 };

    bool answer1Clicked = false;
    bool answer2Clicked = false;
    bool answer3Clicked = false;

    int wrongCounter = 0;

    Texture2D background = LoadTexture("../assets/images/gameQuiz.png");
    Texture2D blackHole = LoadTexture("../assets/images/blackHole.png");
    Texture2D spaceShip = LoadTexture("../assets/images/rocket.png");
    Texture2D tracks = LoadTexture("../assets/images/tracks.png");

    std::string questions[8] = { "What is dark matter?",
    "How do black holes form?", "What role do magnetic\nfields play in shaping\ncelestial bodies in space?",
    "How do astronomers detect\nand study exoplanets?", "What is cosmic microwave\nbackground radiation?",
    "How do gravitational\nwaves offer new insights\ninto astronomical phenomena?",
    "What is dark energy?", "How do phenomena like\nsupernovas impact the\ncomposition of galaxies\nand the formation of elements?"
    };

    std::string rightAnswers[8] = {"Invisible, mysterious mass.", "Star collapse, supernova.",
    "Guidance, alignment, protection.", "Observation, instruments, analysis.", "Ancient light echo.",
    "Space-time ripples, observations.", "Unknown cosmic force.", "Heavy element production."
    };

    std::string wrongAnswers1[8] = {"Cosmic invisible shadows.", "Galactic phantom substance.",
    "Cosmic doughnuts emerge.", "Stellar confetti formation.", "Celestial body puppetry.", "Galactic hairdressers' influence.",
    "Psychic star-gazing.", "Tea leag reading."
    };

    std::string wrongAnswers2[8] = {
        "Galactic disco glow.", "Microwave oven residue.", "Alien dance signals.",
        "Celestial taco waves.", "Galactic happiness field.", "Cosmic rainbow essence.", 
        "Celestial spice mixing.", "Galactic confetti party."
    };

    int num = GetRandomValue(0, 2);
    int questionCounter = 0;

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(blackHole, 900, 50, RAYWHITE);
        DrawTexture(spaceShip, 250, 250, RAYWHITE);
        DrawTexture(tracks, 50, 300, RAYWHITE);

        DrawTextEx(boldPoppins, questions[questionCounter].c_str(), Vector2(500, 50), 50, 5, WHITE);
        
        DrawRectangleRec(answer1, GetColor(0x312b4700));
        DrawRectangleRec(answer2, GetColor(0x312b4700));
        DrawRectangleRec(answer3, GetColor(0x312b4700));

        if (num == 0)
        {
            DrawTextEx(boldPoppins, rightAnswers[questionCounter].c_str(), Vector2(500, 600), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers1[questionCounter].c_str(), Vector2(500, 700), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers2[questionCounter].c_str(), Vector2(500, 800), 50, 5, WHITE);

            if ((CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || (CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
            {
                wrongCounter++;
                DrawTexture(spaceShip, 450, 250, RAYWHITE);
            }
        }

        if (num == 1)
        {
            DrawTextEx(boldPoppins, wrongAnswers1[questionCounter].c_str(), Vector2(500, 600), 50, 5, WHITE);
            DrawTextEx(boldPoppins, rightAnswers[questionCounter].c_str(), Vector2(500, 700), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers2[questionCounter].c_str(), Vector2(500, 800), 50, 5, WHITE);
        }

        if (num == 2)
        {
            DrawTextEx(boldPoppins, wrongAnswers1[questionCounter].c_str(), Vector2(500, 600), 50, 5, WHITE);
            DrawTextEx(boldPoppins, wrongAnswers2[questionCounter].c_str(), Vector2(500, 700), 50, 5, WHITE);
            DrawTextEx(boldPoppins, rightAnswers[questionCounter].c_str(), Vector2(500, 800), 50, 5, WHITE);
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

        EndDrawing();
    }
}
