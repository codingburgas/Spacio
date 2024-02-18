#include "gameQuiz.h"
#include <iostream>

void gameQuiz()
{
	Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
	Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Rectangle answer1 = { 525, 600, 400, 50 };
    Rectangle answer2 = { 525, 700, 400, 50 };
    Rectangle answer3 = { 525, 800, 400, 50 };

    bool answer1Clicked = false;
    bool answer2Clicked = false;
    bool answer3Clicked = false;

    int wrongCounter = 0;

    Texture2D background = LoadTexture("../assets/images/gameQuiz.png");
    Texture2D blackHole = LoadTexture("../assets/images/blackHole.png");
    Texture2D spaceShip = LoadTexture("../assets/images/rocket.png");
    Texture2D tracks = LoadTexture("../assets/images/tracks.png");

    const char* questions[8] = { "What is dark matter?",
    "How do black holes form?", "What role do magnetic fields play in shaping celestial bodies in space?",
    "How do astronomers detect and study exoplanets?", "What is cosmic microwave background radiation?",
    "How do gravitational waves offer new insights into astronomical phenomena?",
    "What is dark energy?", "How do phenomena like supernovae impact the composition of galaxies and the formation of elements?"
    };

    const char* rightAnswers[8] = {"Invisible, mysterious mass.", "Star collapse, supernova.",
    "Guidance, alignment, protection.", "Observation, instruments, analysis.", "Ancient light echo.",
    "Space-time ripples, observations.", "Unknown cosmic force.", "Heavy element production."
    };

    const char* wrongAnswers[16] = {"Cosmic invisible shadows.", "Galactic phantom substance."
    "Cosmic doughnuts emerge.", "Stellar confetti formation.", "Celestial body puppetry.", "Galactic hairdressers' influence.",
    "Psychic star-gazing.", "Tea leaf readings.", "Galactic disco glow.", "Microwave oven residue.", "Alien dance signals.",
    "Celestial taco waves.", "Galactic happiness field.", "Cosmic rainbow essence.", "Celestial spice mixing.", "Galactic confetti party."
    };

    int questionCounter = 0;

    while (!WindowShouldClose())
    {
        if (CheckCollisionPointRec(GetMousePosition(), answer1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            answer1Clicked = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), answer2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            answer2Clicked = true;
        
        if (CheckCollisionPointRec(GetMousePosition(), answer3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            answer3Clicked = true;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(blackHole, 900, 50, RAYWHITE);
        DrawTexture(spaceShip, 250, 250, RAYWHITE);
        DrawTexture(tracks, 50, 300, RAYWHITE);

        DrawRectangleRec(answer1, GetColor(342245));
        DrawTextEx(boldPoppins, rightAnswers[questionCounter], Vector2{ 665, 500 }, 40, 5, WHITE);

        DrawRectangleRec(answer2, GetColor(342245));
        DrawTextEx(boldPoppins, rightAnswers[questionCounter], Vector2{ 665, 500 }, 40, 5, WHITE);

        DrawRectangleRec(answer3, GetColor(342245));
        DrawTextEx(boldPoppins, rightAnswers[questionCounter], Vector2{ 665, 500 }, 40, 5, WHITE);


        DrawTextEx(boldPoppins, questions[questionCounter], Vector2(450, 50), 50, 5, WHITE);

        if (answer1Clicked)
        {
            questionCounter++;
            answer1Clicked = false;
        }

        if (answer2Clicked)
        {
            questionCounter++;
            answer2Clicked = false;
        }

        if (answer3Clicked)
        {
            questionCounter++;
            answer3Clicked = false;
        }

        if (wrongCounter == 3)
        {
            readyForQuiz();
            break;
        }

        if (questionCounter == 8)
        {
            getStation();
            break;
        }

        EndDrawing();
    }
}

}
