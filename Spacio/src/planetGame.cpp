#include "planetGame.h"

void planetGame() {
    Texture2D background = LoadTexture("../assets/images/spaceGameBackground.png");

    Texture2D rocket = LoadTexture("../assets/images/rocket.png");
    Texture2D badGuysLeft = LoadTexture("../assets/images/badGuysLeft.png");
    Texture2D badGuysRight = LoadTexture("../assets/images/badGuysRight.png");

    Texture2D sun = LoadTexture("../assets/images/objects/sun.png");
    Texture2D mercury = LoadTexture("../assets/images/objects/mercury.png");
    Texture2D venus = LoadTexture("../assets/images/objects/venus.png");
    Texture2D earth = LoadTexture("../assets/images/objects/earth.png");
    Texture2D mars = LoadTexture("../assets/images/objects/mars.png");
    Texture2D jupiter = LoadTexture("../assets/images/objects/jupiter.png");
    Texture2D saturn = LoadTexture("../assets/images/objects/saturn.png");
    Texture2D uranus = LoadTexture("../assets/images/objects/uranus.png");
    Texture2D neptune = LoadTexture("../assets/images/objects/neptune.png");

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    int rocketY = GetScreenHeight();
    int badGuysLeftX = 0 - badGuysLeft.width;
    int badGuysRightX = GetScreenWidth();
    int badGuysSpeed = 5;

    bool firstTextShown = false;
    bool okTextShown = false; 
    int firstTextDuration = 120;
    int frameCounter = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        if (rocketY > GetScreenHeight() / 1.5) {
            rocketY -= 10;
        }

        DrawTexture(rocket, GetScreenWidth() / 2 - rocket.width / 2, rocketY, RAYWHITE);

        switch (chosenPlanetIndex) {
        case 0:
            DrawTexture(sun, GetScreenWidth() / 2 - sun.width / 2, 0, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here the sun is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) { 
                DrawTextEx(Poppins,
                    "Mass: 1.989 × 10^30 kilograms\n"
                    "Diameter: Approximately 1.4 million kilometers\n"
                    "Surface temperature : Around 5,500 °C\n"
                    "Age : Approximately 4.6 billion years\n"
                    "Composition : Hydrogen(74 %) and helium (24 %) \n"
                    "Luminosity : Approximately 3.8 × 10 ^ 26 watts\n"
                    "Distance from Earth : Between 147 and 152 million kilometers\n"
                    "Class : G - type main - sequence star(G2V)",
                    Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins,
                    "Core temperature: Approximately 15 million C\n"
                    "Surface gravity: 28 times greater than Earth's\n"
                    "Energy production: Converting hydrogen into helium\n"
                    "Solar wind speed: 400 to 700 kilometers per second\n"
                    "Rotation period: Every 25 days at the equator\n"" and around 35 days near the poles",
                    Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);

                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else{
                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    DrawTextEx(Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
                    DrawTextEx(Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
                    if (badGuysLeftX < 0) {
                        badGuysLeftX += badGuysSpeed;
                    }
                    DrawTexture(badGuysLeft, badGuysLeftX, 0, RAYWHITE);
                    if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
                        badGuysRightX -= badGuysSpeed;
                    }
                    DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
                }
            }
            break;
        case 1:
            DrawText("You chose Mercury.", 100, 100, 20, BLACK);
            break;
        case 2:
            DrawText("You chose Venus.", 100, 100, 20, BLACK);
            break;
        case 3:
            DrawText("You chose Earth.", 100, 100, 20, BLACK);
            break;
        case 4:
            DrawText("You chose Mars.", 100, 100, 20, BLACK);
            break;
        case 5:
            DrawText("You chose Jupiter.", 100, 100, 20, BLACK);
            break;
        case 6:
            DrawText("You chose Saturn.", 100, 100, 20, BLACK);
            break;
        case 7:
            DrawText("You chose Uranus.", 100, 100, 20, BLACK);
            break;
        case 8:
            DrawText("You chose Neptune.", 100, 100, 20, BLACK);
            break;
        default:
            DrawText("No planet chosen.", 100, 100, 20, BLACK);
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(rocket);
}
