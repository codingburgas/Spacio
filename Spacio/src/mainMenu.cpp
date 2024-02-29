#include "mainMenu.h"
#include "userName.h"

void mainMenu()
{
    const int screenWidth = 1440;
    const int screenHeight = 900;

    GameState state = GameState::Intro;

    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Spacio");

    InitAudioDevice();

    InitIntroWindow();

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        if(state == GameState::Intro)
        {
            intro(state);
        }
        else if (state == GameState::NONE)
        {
            break;
        }
        else if (state == GameState::UserName)
        {
            userName(state);
        }
        else if (state == GameState::CharacterPick)
        {
            characterPick(state);
        }
        else if (state == GameState::ChooseLearningStyle)
        {
            chooseLearningStyle(state);
        }
        else if (state == GameState::Questions)
        {
            questions(state);
        }
        else if (state == GameState::UserConfirm)
        {
            userConfirm(state);
        }
        else if (state == GameState::GetStation)
        {
            getStation(state);
        }
        else if (state == GameState::PickPlanet)
        {
            pickPlanet(state);
        }
        else if (state == GameState::ParticlePick)
        {
            particlePick(state);
        }
        else if (state == GameState::HiggsBoson)
        {
            HiggsFieldGame(state);
        }
        else if (state == GameState::NatureScript)
        {
            natureScript(state);
        }
        else if (state == GameState::ReadyForQuiz)
        {
            readyForQuiz(state);
        }
        else if (state == GameState::GameQuiz)
        {
            gameQuiz(state);
        }
        else if (state == GameState::EndScreen)
        {
            endScreen(state);
        }
        else if (state == GameState::SpaceShip)
        {
            spaceShip(state);
        }

        EndDrawing();
    }
}