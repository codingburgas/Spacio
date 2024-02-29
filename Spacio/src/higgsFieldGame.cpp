#include "higgsFieldGame.h"
#include "basicData.h"
#include "particlePick.h"

void InitHiggsBosonWindow()
{
    basicData.background = LoadTexture("../assets/images/higgsfieldBg.png");
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    higgsBoson.horizontalStep = 16;
    higgsBoson.particleVertical = 707;
    higgsBoson.particleHorizontal = -1272;

    higgsBoson.particle = LoadTexture("../assets/images/particle.png");
    higgsBoson.girlPhoton = LoadMusicStream("../assets/audios/photonsFemale.mp3");
    higgsBoson.boyPhoton = LoadMusicStream("../assets/audios/photonsMale.mp3");
    higgsBoson.girlElectron = LoadMusicStream("../assets/audios/electronsFemale.mp3");
    higgsBoson.boyElectron = LoadMusicStream("../assets/audios/electronsMale.mp3");
    higgsBoson.girlHiggs = LoadMusicStream("../assets/audios/higgsFemale.mp3");
    higgsBoson.boyHiggs = LoadMusicStream("../assets/audios/higgsMale.mp3");

    basicData.voiceTime = 0.0;
    higgsBoson.electronAudioTime = 0.0;
    higgsBoson.higgsAudioTime = 0.0;

    if (hasMass) {
        higgsBoson.particleVertical -= 84;
        higgsBoson.horizontalStep /= 2;
    }
}

bool loadHiggsBoson = true;

const int verticalStep = 84;
const int lowest = 707;
const int highest = 539;
const int leftStart = -1272;
const int rightEnd = -60;

void HiggsFieldGame(GameState& state) {

    if (loadHiggsBoson)
    {
        InitHiggsBosonWindow();
        loadHiggsBoson = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);

        PlayMusicStream(higgsBoson.girlPhoton);
        PlayMusicStream(higgsBoson.boyPhoton);
        PlayMusicStream(higgsBoson.girlElectron);
        PlayMusicStream(higgsBoson.boyElectron);
        PlayMusicStream(higgsBoson.girlHiggs);
        PlayMusicStream(higgsBoson.boyHiggs);
    }

        DrawTexture(basicData.background, 0, 0, RAYWHITE);

        // Particle movement based on user interaction
        if (IsKeyPressed(KEY_UP) && higgsBoson.particleVertical > highest) {
            higgsBoson.particleVertical -= verticalStep;
            higgsBoson.horizontalStep /= 2;
        }
        if (IsKeyPressed(KEY_DOWN) && higgsBoson.particleVertical < lowest) {
            higgsBoson.particleVertical += verticalStep;
            higgsBoson.horizontalStep *= 2;
        }
        // Particle bouncing off borders
        if (higgsBoson.particleHorizontal > rightEnd || higgsBoson.particleHorizontal < leftStart) {
            higgsBoson.horizontalStep =- higgsBoson.horizontalStep;
        }

        higgsBoson.particleHorizontal += higgsBoson.horizontalStep;

        // Draw particle
        DrawTexture(higgsBoson.particle, higgsBoson.particleHorizontal, higgsBoson.particleVertical, RAYWHITE);

        // Determine particle position and display information
        int position = (lowest - higgsBoson.particleVertical) / verticalStep;

        std::string massText = "Mass: ";
        std::string speedText = "Speed: ";
        std::string infoText;

        switch (position) {
        case 0:
            massText += "0";
            speedText += "speed of light";
            infoText = "Photons don't interact with the higgsField so they are very fast.";
            // Play photon audio
            if (girlVoice) {
                if (IsMusicStreamPlaying(higgsBoson.girlPhoton) and basicData.voiceTime < 3.4)
                {
                    UpdateMusicStream(higgsBoson.girlPhoton);
                    basicData.voiceTime += GetFrameTime();
                }

            }
            else if (boyVoice) {
                if (IsMusicStreamPlaying(higgsBoson.boyPhoton) and basicData.voiceTime < 4)
                {
                    UpdateMusicStream(higgsBoson.boyPhoton);
                    basicData.voiceTime += GetFrameTime();
                }
            }
            break;
        case 1:
            massText += "0.511 MeV/c^2";
            speedText += "There is a certain speed.";
            infoText = "Electrons interact with the field a little so they are fast.";
            if (girlVoice) {
                // Play electron audio
                if (IsMusicStreamPlaying(higgsBoson.girlElectron) and higgsBoson.electronAudioTime < 3.5)
                {
                    UpdateMusicStream(higgsBoson.girlElectron);
                    higgsBoson.electronAudioTime += GetFrameTime();
                }
            }
            else if (boyVoice) {
                if (IsMusicStreamPlaying(higgsBoson.boyElectron) and higgsBoson.electronAudioTime < 3.7)
                {
                    UpdateMusicStream(higgsBoson.boyElectron);
                    higgsBoson.electronAudioTime += GetFrameTime();
                }
            }
            break;
        case 2:
            massText += "125.11 GeV/c^2";
            speedText += "Moves slower.";
            infoText = "Higgs bosons interact strongly so they are slow.";
            if (girlVoice) {
                // Play Higgs boson audio
                if (IsMusicStreamPlaying(higgsBoson.girlHiggs) and higgsBoson.higgsAudioTime < 3)
                {
                    UpdateMusicStream(higgsBoson.girlHiggs);
                    higgsBoson.higgsAudioTime += GetFrameTime();
                }
            }
            else if (boyVoice) {
                if (IsMusicStreamPlaying(higgsBoson.boyHiggs) and higgsBoson.higgsAudioTime < 3.1)
                {
                    UpdateMusicStream(higgsBoson.boyHiggs);
                    higgsBoson.higgsAudioTime += GetFrameTime();
                }
            }
            break;
        }

        // Draw information text
        DrawTextEx(basicData.boldPoppins, massText.c_str(), Vector2{ 114, 68 }, 48, 5, WHITE);
        DrawTextEx(basicData.boldPoppins, speedText.c_str(), Vector2{ 114, 140 }, 48, 5, WHITE);
        DrawTextEx(basicData.boldPoppins, infoText.c_str(), Vector2{ 114, 247 }, 40, 5, WHITE);
        DrawTextEx(basicData.Poppins, "Press Space to return home", Vector2{ 114, 460 }, 40, 5, GRAY);

        // Check for space key press to return to continue
        if (IsKeyPressed(KEY_SPACE)) {
            state == GameState::EndScreen;
        }
}