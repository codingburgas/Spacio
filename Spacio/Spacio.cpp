#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

void homeMenu()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Spacio");

    InitAudioDevice();

    Music music = LoadMusicStream("../assets/audios/cornfieldChase.mp3");
    PlayMusicStream(music);

    Music welcomeAudio = LoadMusicStream("../assets/audios/welcomeAudio.mp3");
    PlayMusicStream(welcomeAudio);

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Image logo = LoadImage("../assets/images/logo.png");
    Image image = LoadImage("../assets/images/mainCharacter.png");
    Texture2D mainCharacter = LoadTextureFromImage(image);

    SetWindowIcon(logo);

    Rectangle planetButton = { 648, 400, 150, 40 };
    Rectangle higgsButton = { 648, 480, 180, 40 };
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

    float welcomeAudioSecond = GetMusicTimeLength(welcomeAudio);
    float audioTime = 0.0;

    SetTextLineSpacing(40);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        if (IsMusicStreamPlaying(welcomeAudio) and audioTime < 2.7)
        {
            UpdateMusicStream(welcomeAudio);
            audioTime += GetFrameTime();
        }

        if (CheckCollisionPointRec(GetMousePosition(), planetButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            buttonClickedPlanets = true;
        }

        if (CheckCollisionPointRec(GetMousePosition(), higgsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            buttonClickedHiggs = true;
        }

        BeginDrawing();

        ClearBackground(GetColor(0x312b47ff));
        DrawTexture(mainCharacter, -20, 80, WHITE);

        DrawTextEx(boldPoppins, "Welcome, choose what you want to learn about", Vector2{ 200, 70 }, 40, 5, WHITE);

        DrawTextEx(Poppins, questions[questionCounter], Vector2{ 600, 240 }, 35, 5, WHITE);

        DrawRectangleRec(planetButton, GetColor(0x312b4700));
        DrawTextEx(Poppins, planetsAnswers[questionCounter], Vector2{ 665, 400 }, 35, 5, WHITE);

        if (buttonClickedPlanets)
        {
            planets++;
            questionCounter++;
            buttonClickedPlanets = false;
        }

        DrawRectangleRec(higgsButton, GetColor(0x312b4700));
        DrawTextEx(Poppins, higgsAnswers[questionCounter], Vector2{ 665, 480 }, 35, 5, WHITE);

        if (buttonClickedHiggs)
        {
            higgs++;
            questionCounter++;
            buttonClickedHiggs = false;
        }

        EndDrawing();
    }

    StopMusicStream(music);
    StopMusicStream(welcomeAudio);


    CloseAudioDevice();
}

int main()
{
    homeMenu();
}