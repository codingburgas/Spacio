#include "questions.h"

void questions(bool boyVoice, bool girlVoice)
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/questionsBackground.png");

    Rectangle planetButton = { 648, 500, 150, 40 };
    Rectangle higgsButton = { 648, 580, 180, 40 };
    bool buttonClickedPlanets = false;
    bool buttonClickedHiggs = false;

    const char* questions[8] = { "Do you choose to gaze at the stars\nor delve into the study\nof micro-particles?",
        "Do you prefer exploring galaxies\nor focusing on elementary particles?",
        "Does your excitement come from\ncosmic phenomena or\natomic structures?",
        "Would you rather investigate black\nholes or examine subatomic\ninteractions?",
        "Do you ponder more on processes in\nstellar cores or on experimental\nresults in particles?",
        "Are you into studying gravitational\nwaves or interactions between\nquarks?",
        "Would you enjoy astronomical\nobservation or analyzing data\nfrom particle experiments ?",
        "Do you prefer examining the vast\nstructures of the Universe or delving\ninto the basics of composite particles?" };

    const char* planetsAnswers[8] = { "Stars", "Galaxies", "Cosmic phenomena", "Black holes",
        "Stellar cores", "Gravitational waves", "Astronomical observation", "Vast structures" };

    const char* higgsAnswers[8] = { "Micro-particles", "Elementary particles", "Atomic structures", "Subatomic interactions",
        "Experimental results", "Interactions between quarks", "Analysis of particle data", "Composite particles" };

    int questionCounter = 0;
    int planets = 0;
    int higgs = 0;

    SetTextLineSpacing(38);

    while (!WindowShouldClose())
    {
        if (CheckCollisionPointRec(GetMousePosition(), planetButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            buttonClickedPlanets = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), higgsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            buttonClickedHiggs = true;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTextEx(boldPoppins, "Welcome, choose what you want to learn about", Vector2{ 250, 160 }, 50, 5, WHITE);

        DrawTextEx(Poppins, questions[questionCounter], Vector2{ 600, 320 }, 40, 5, WHITE);

        DrawRectangleRec(planetButton, GetColor(0x312b4700));
        DrawTextEx(boldPoppins, planetsAnswers[questionCounter], Vector2{ 665, 500 }, 40, 5, WHITE);

        if (buttonClickedPlanets)
        {
            planets++;
            questionCounter++;
            buttonClickedPlanets = false;
        }

        DrawRectangleRec(higgsButton, GetColor(0x312b4700));
        DrawTextEx(boldPoppins, higgsAnswers[questionCounter], Vector2{ 665, 580 }, 40, 5, WHITE);

        if (buttonClickedHiggs)
        {
            higgs++;
            questionCounter++;
            buttonClickedHiggs = false;
        }

        EndDrawing();

    }

}
