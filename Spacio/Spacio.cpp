#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

void homeMenu()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Spacio");

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    int questionCounter = 0;

    const char* questions[8] = { "Do you choose to gaze at the stars\nor delve into the study\nof micro-particles?",
        "Do you prefer exploring galaxies\nor focusing on elementary particles?",
        "Does your excitement come from\ncosmic phenomena or\natomic structures?",
        "Would you rather investigate black\nholes or examine subatomic\ninteractions?",
        "Do you ponder more on processes in\nstellar cores or on experimental\nresults in particles?",
        "Are you into studying gravitational\nwaves or interactions between\nquarks?",
        "Would you enjoy astronomical\nobservation or analyzing data\nfrom particle experiments ?",
        "Do you prefer examining the vast\nstructures of the Universe or delving\ninto the basics of composite particles?" };

    SetTextLineSpacing(38);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(Poppins, questions[questionCounter], Vector2{ 600, 260 }, 35, 5, WHITE);

        EndDrawing();
    }
}

int main()
{
    homeMenu();
}