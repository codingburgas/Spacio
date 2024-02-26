#include "mainMenu.h"

void mainMenu()
{
    const int screenWidth = 1440;
    const int screenHeight = 900;

    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Spacio");

    InitAudioDevice();

    intro();
    //pickPlanet();
    //spaceShip();
}