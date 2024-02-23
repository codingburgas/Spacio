#include "mainMenu.h"

void mainMenu()
{
    const int screenWidth = 1440;
    const int screenHeight = 900;

    Image logo = LoadImage("./assets/images/logo.png");

    SetWindowIcon(logo);
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Spacio");

    //chooseLearningStyle();
    //HiggsFieldGame(true);
    intro();
    //spaceShip();
}