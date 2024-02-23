#include "mainMenu.h"

void mainMenu()
{
    const int screenWidth = 1440;
    const int screenHeight = 900;

    Image logo = LoadImage("./assets/images/logo.png");

    SetWindowIcon(logo);

    InitWindow(screenWidth, screenHeight, "Spacio");

    HiggsFieldGame(true);
    //intro();
    //spaceShip();
}