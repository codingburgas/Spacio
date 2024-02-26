#include "higgsFieldGame.h"

void HiggsFieldGame(bool hasMass, std::string userNameStr, bool girlVoice, bool boyVoice) {


    Texture2D background = LoadTexture("../assets/images/higgsfieldBg.png");
    Texture2D particle = LoadTexture("../assets/images/particle.png");

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    const int verticalStep = 84;
    int horizontalStep = 16;
    const int lowest = 707;
    const int highest = 539;
    const int leftStart = -1272;
    const int rightEnd = -60;
    int particleVertical = 707;
    int particleHorizontal = -1272;

    Music girlPhoton = LoadMusicStream("../assets/audios/photonsFemale.mp3");
    Music boyPhoton = LoadMusicStream("../assets/audios/photonsMale.mp3");
    Music girlElectron = LoadMusicStream("../assets/audios/electronsFemale.mp3");
    Music boyElectron = LoadMusicStream("../assets/audios/electronsMale.mp3");
    Music girlHiggs = LoadMusicStream("../assets/audios/higgsFemale.mp3");
    Music boyHiggs = LoadMusicStream("../assets/audios/higgsMale.mp3");

    PlayMusicStream(girlPhoton);
    PlayMusicStream(boyPhoton);
    PlayMusicStream(girlElectron);
    PlayMusicStream(boyElectron);
    PlayMusicStream(girlHiggs);
    PlayMusicStream(boyHiggs);

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawTexture(background, 0, 0, RAYWHITE);

        if (IsKeyPressed(KEY_UP) && particleVertical > highest) {
            particleVertical -= verticalStep;
            horizontalStep /= 2;
        }
        if (IsKeyPressed(KEY_DOWN) && particleVertical < lowest) {
            particleVertical += verticalStep;
            horizontalStep *= 2;
        }

        if (particleHorizontal > rightEnd || particleHorizontal < leftStart) {
            horizontalStep = -horizontalStep;
        }

        particleHorizontal += horizontalStep;

        DrawTexture(particle, particleHorizontal, particleVertical, RAYWHITE);

        int position = (lowest - particleVertical) / verticalStep;

        std::string massText = "Mass: ";
        std::string speedText = "Speed: ";
        std::string infoText;

        switch (position) {
        case 0:
            massText += "0";
            speedText += "speed of light";
            infoText = "Photons don't interact with the higgsField so they are very fast.";
            if (girlVoice) {
                UpdateMusicStream(girlPhoton);
            }
            else if (boyVoice) {
                UpdateMusicStream(boyPhoton);
            }
            break;
        case 1:
            massText += "0.511 MeV/c^2";
            speedText += "There is a certain speed.";
            infoText = "Electrons interact with the field a little so they are fast.";
            if (girlVoice) {
                UpdateMusicStream(girlElectron);
            }
            else if (boyVoice) {
                UpdateMusicStream(boyElectron);
            }
            break;
        case 2:
            massText += "125.11 GeV/c^2";
            speedText += "Moves slower.";
            infoText = "Higgs bosons interact strongly so they are slow.";
            if (girlVoice) {
                UpdateMusicStream(girlHiggs);
            }
            else if (boyVoice) {
                UpdateMusicStream(boyHiggs);
            }
            break;
        }

        DrawTextEx(boldPoppins, massText.c_str(), Vector2{ 114, 68 }, 48, 5, WHITE);
        DrawTextEx(boldPoppins, speedText.c_str(), Vector2{ 114, 140 }, 48, 5, WHITE);
        DrawTextEx(boldPoppins, infoText.c_str(), Vector2{ 114, 247 }, 40, 5, WHITE);
        DrawTextEx(Poppins, "Press Space to return home", Vector2{ 114, 460 }, 40, 5, GRAY);

        ClearBackground(RAYWHITE);

        EndDrawing();
        if (IsKeyPressed(KEY_SPACE)) {
            endScreen(userNameStr, girlVoice, boyVoice);
            break;
        }
    }
    UnloadTexture(background);
    UnloadTexture(particle);
    UnloadFont(Poppins);
    UnloadFont(boldPoppins);
    UnloadMusicStream(girlPhoton);
    UnloadMusicStream(boyPhoton);
    UnloadMusicStream(girlElectron);
    UnloadMusicStream(boyElectron);
    UnloadMusicStream(girlHiggs);
    UnloadMusicStream(boyHiggs);

   
}