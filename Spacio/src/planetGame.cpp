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
    int firstTextDuration = 120;
    int frameCounter = 0;
    int posY = (GetScreenHeight() - mercury.height) / 5;

    bool firstTextShown = false;
    bool dialogShown = false;
    bool dialogShown2 = false;
    bool okTextShown = false; 
    // make info less
    const char* leftInformation[9] = {
    "Mass: 1.989 Ч 10^30 kilograms\n Diameter: Approximately 1.4 million km\nSurface temperature : Around 5,500 °C\nAge : Approximately 4.6 billion years\nComposition : Hydrogen(74 %) and helium (24 %) \nComposition : Hydrogen(74 %) and helium (24 %) \nLuminosity : Approximately 3.8 Ч 10 ^ 26 watts\nDistance from Earth : Between 147 and 152 million kilometers\nClass : G - type main - sequence star(G2V)",
    "Mass: 3.285 × 10^23 kilograms\nDiameter: Approximately 4,880 km\nSurface temperature: Between -173°C to 427°C\nAge: Approximately 4.5 billion years\nComposition: Mostly silicate rock and metals\nDistance from Sun: Between 46 and 70 million kilometers\nClass: Terrestrial planet",
    "Mass: 4.8675 × 10^24 kilograms\nDiameter: Approximately 12,104 km\nSurface temperature: Around 462 °C\nAge: Approximately 4.5 billion years\nComposition: Carbon dioxide (96.5%), nitrogen (3.5%)\nDistance from Earth: Between 38 million kilometers and 261 million kilometers\nClass: Terrestrial (rocky) planet",
    "Mass: 5.972 × 10^24 kilograms\nDiameter: Approximately 12,742 km\nSurface temperature: Around 15 °C\nAge: Approximately 4.5 billion years\nComposition: Iron (32.1%), oxygen (30.1%), silicon (15.1%), magnesium (13.9%)\nDistance from Sun: Approximately 149.6 million kilometers\nClass: Terrestrial (rocky) planet",
    "Mass: 6.4171 × 10^23 kilograms\nDiameter: Approximately 6,779 km\nSurface temperature: Around -63 °C\nAge: Approximately 4.6 billion years\nComposition: Iron oxide (88.8%), silicon dioxide (7.2%)\nDistance from Sun: Approximately 206.7 million kilometers\nClass: Terrestrial (rocky) planet",
    "Mass: 1.898 × 10^27 kilograms\nDiameter: Approximately 139,820 km\nSurface temperature: Around -145 °C\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (89.8%), helium (10.2%)\nLuminosity: None (not a star)\nDistance from Sun: Approximately 778.5 million kilometers\nClass: Gas giant planet",
    "Mass: 5.683 × 10^26 kilograms\nDiameter: Approximately 116,460 km\nSurface temperature: Around -178 °C\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (96.3%), helium (3.3%)\nLuminosity: None (not a star)\nDistance from Sun: Approximately 1.43 billion kilometers\nClass: Gas giant planet",
    "Mass: 8.681 × 10^25 kilograms\nDiameter: Approximately 50,724 km\nSurface temperature: Around -197 °C\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (83%), helium (15%), methane (2%)\nLuminosity: None (not a star)\nDistance from Sun: Approximately 2.88 billion kilometers\nClass: Ice giant planet",
    "Mass: 1.024 × 10^26 kilograms\nDiameter: Approximately 49,244 km\nSurface temperature: Around -201 °C\nAge: Approximately 4.5 billion years\nComposition: Hydrogen (80%), helium (19%), methane (1.5%)\nLuminosity: None (not a star)\nDistance from Sun: Approximately 4.5 billion kilometers\nClass: Ice giant planet"
    };
    const char* rightInformation[9] = {
        "Core temperature: Approximately 15 million C\nSurface gravity: 28 times greater than Earth's\n Energy production: Converting hydrogen into helium\nSolar wind speed: 400 to 700 kilometers per second\nRotation period: Every 25 days at the equator\n and around 35 days near the poles",
        "Core temperature: Approximately 4,000°C\nSurface gravity: 0.38 times that of Earth's\nEnergy production: Primarily reflects sunlight\nSolar wind speed: Around 400 kilometers per second\nRotation period: Approximately 58.6 Earth days\nTidally locked: Rotates three times on its axis for every two orbits around the Sun",
        "Core temperature: Approximately 5,000°C\nSurface gravity: 0.9 times that of Earth's\nEnergy production: Reflects and absorbs sunlight\nSolar wind speed: Around 400 kilometers per second\nRotation period: Approximately 243 Earth days\nAtmospheric pressure: Around 92 times that of Earth's\nComposition: Primarily carbon dioxide (96.5%) with traces of nitrogen and other gases",
        "Core temperature: Approximately 5,700°C\nSurface gravity: About 9.8 m/s²\nEnergy production: Various sources, including solar radiation\nSolar wind speed: Approximately 400 kilometers per second\nRotation period: Approximately 24 hours\nOrbital period: Approximately 365.25 days around the Sun",
        "Core temperature: Approximately 1,500°C\nSurface gravity: 0.38 times that of Earth's\nEnergy production: Receives sunlight\nSolar wind speed: Varies between 200 and 500 kilometers per second\nRotation period: Approximately 24.6 hours\nOrbital period: Approximately 687 Earth days",
        "Core temperature: Approximately 24,000°C\nSurface gravity: 2.5 times greater than Earth's\nEnergy production: Releases more heat than it receives from the Sun\nSolar wind speed: Around 700 kilometers per second\nRotation period: Approximately 9.9 hours\nMagnetic field: Strongest in the solar system",
        "Core temperature: Approximately 11,700°C\nSurface gravity: 1.06 times that of Earth's\nEnergy production: Primarily reflects sunlight\nSolar wind speed: About 400 kilometers per second\nRotation period: Approximately 10.7 hours\nRings: Composed mostly of ice particles and dust",
        "Core temperature: Approximately 5,000°C\nSurface gravity: 0.89 times that of Earth's\nEnergy production: Absorbs and reflects sunlight\nSolar wind speed: Around 250 kilometers per second\nRotation period: Approximately 17.2 hours\nTilt: Rotates on its side, with extreme axial tilt",
        "Core temperature: Approximately 7,000°C\nSurface gravity: 1.12 times that of Earth's\nEnergy production: Absorbs and reflects sunlight\nSolar wind speed: About 200 kilometers per second\nRotation period: Approximately 16.1 hours\nAtmospheric features: Dynamic weather patterns and powerful storms"
    };

    const char* firstQuestion[9] = {
    "What is the mass of the Sun?",
    "What is the mass of Mercury?",
    "What is the mass of Venus?",
    "What is the mass of Earth?",
    "What is the mass of Mars?",
    "What is the mass of Jupiter?",
    "What is the mass of Saturn?",
    "What is the mass of Uranus?",
    "What is the mass of Neptune?",
    };
    const char* secondQuestion[9] = {
        "What is the approximate diameter of the Sun?",
        "What is the approximate diameter of Mercury?",
        "What is the approximate diameter of Venus?",
        "What is the approximate diameter of Earth?",
        "What is the approximate diameter of Mars?",
        "What is the approximate diameter of Jupiter?",
        "What is the approximate diameter of Saturn?",
        "What is the approximate diameter of Uranus?",
        "What is the approximate diameter of Neptune?",
    };
    const char* thirdQuestion[9] = {
        "What is the surface temperature of the Sun?",
        "What is the surface temperature of Mercury?",
        "What is the surface temperature of Venus?",
        "What is the surface temperature of Earth?",
        "What is the surface temperature of Mars?",
        "What is the surface temperature of Jupiter?",
        "What is the surface temperature of Saturn?",
        "What is the surface temperature of Uranus?",
        "What is the surface temperature of Neptune?",
    };
    const char* forthQuestion[9] = {
        "How old is the Sun?",
        "How old is Mercury?",
        "How old is Venus?",
        "How old is Earth?",
        "How old is Mars?",
        "How old is Jupiter?",
        "How old is Saturn?",
        "How old is Uranus?",
        "How old is Neptune?",
    };
    const char* fifthQuestion[9] = {
        "What is the composition of the Sun?",
        "What is the composition of Mercury?",
        "What is the composition of Venus?",
        "What is the composition of Earth?",
        "What is the composition of Mars?",
        "What is the composition of Jupiter?",
        "What is the composition of Saturn?",
        "What is the composition of Uranus?",
        "What is the composition of Neptune?",
    };
    const char* sixthQuestion[9] = {
        "What is the primary process of energy production in the Sun?",
        "What is the primary process of energy production in Mercury?",
        "What is the primary process of energy production in Venus?",
        "What is the primary process of energy production in Earth?",
        "What is the primary process of energy production in Mars?",
        "What is the primary process of energy production in Jupiter?",
        "What is the primary process of energy production in Saturn?",
        "What is the primary process of energy production in Uranus?",
        "What is the primary process of energy production in Neptune?",
    };

    const char* rightAnswer1[9] = {
        "1.989 * 10^30 kilograms",
        "3.285 × 10^23 kilograms",
        "4.8675 × 10^24 kilograms",
        "5.972 × 10^24 kilograms",
        "6.4171 × 10^23 kilograms",
        "1.898 × 10^27 kilograms",
        "5.683 × 10^26 kilograms",
        "8.681 × 10^25 kilograms",
        "1.024 × 10^26 kilograms",
    };
    const char* rightAnswer2[9] = {
        "Approximately 1.4 million km",
        "Approximately 4,880 km",
        "Approximately 12,104 km",
        "Approximately 12,742 km",
        "Approximately 6,779 km",
        "Approximately 139,820 km",
        "Approximately 116,460 km",
        "Approximately 50,724 km",
        "Approximately 49,244 km",
    };
    const char* rightAnswer3[9] = {
        "Around 5,500 °C",
        "Between -173°C to 427°C",
        "Around 462 °C",
        "Around 15 °C",
        "Around -63 °C",
        "Around -145 °C",
        "Around -178 °C",
        "Around -197 °C",
        "Around -201 °C",
    };
    const char* rightAnswer4[9] = {
        "4.6 billion years",
        "Approximately 4.5 billion years",
        "Approximately 4.5 billion years",
        "Approximately 4.5 billion years",
        "Approximately 4.6 billion years",
        "Approximately 4.5 billion years",
        "Approximately 4.5 billion years",
        "Approximately 4.5 billion years",
        "Approximately 4.5 billion years",
    };
    const char* rightAnswer5[9] = {
        "Hydrogen(74 %) and helium (24 %)",
        "Mostly silicate rock and metals",
        "Carbon dioxide (96.5%), nitrogen (3.5%)",
        "Iron (32.1%), oxygen (30.1%), silicon (15.1%), magnesium (13.9%)",
        "Iron oxide (88.8%), silicon dioxide (7.2%)",
        "Hydrogen (89.8%), helium (10.2%)",
        "Hydrogen (96.3%), helium (3.3%)",
        "Hydrogen (83%), helium (15%), methane (2%)",
        "Hydrogen (80%), helium (19%), methane (1.5%)",
    };
    const char* rightAnswer6[9] = {
        "Converting hydrogen into helium",
        "Primarily reflects sunlight",
        "Reflects and absorbs sunlight",
        "Various sources, including solar radiation",
        "Receives sunlight",
        "Releases more heat than it receives from the Sun",
        "Primarily reflects sunlight",
        "Absorbs and reflects sunlight",
        "Absorbs and reflects sunlight",
    };

    const char* wrongAnswer1[9] = {
        "1.989 * 10^29 kilograms",
        "3.285 × 10^22 kilograms",
        "4.8675 × 10^23 kilograms",
        "5.972 × 10^23 kilograms",
        "6.4171 × 10^22 kilograms",
        "1.898 × 10^26 kilograms",
        "5.683 × 10^25 kilograms",
        "8.681 × 10^24 kilograms",
        "1.024 × 10^25 kilograms",
    };
    const char* wrongAnswer2[9] = {
        "Approximately 1.2 million km",
        "Approximately 5,000 km",
        "Approximately 10,000 km",
        "Approximately 10,000 km",
        "Approximately 7,000 km",
        "Approximately 150,000 km",
        "Approximately 110,000 km",
        "Approximately 60,000 km",
        "Approximately 45,000 km",
    };
    const char* wrongAnswer3[9] = {
        "Around 7,000 °C",
        "Between -200°C to 500°C",
        "Around 500 °C",
        "Around 20 °C",
        "Around -50 °C",
        "Around -200 °C",
        "Around -200 °C",
        "Around -180 °C",
        "Around -210 °C",
    };
    const char* wrongAnswer4[9] = {
        "3.8 billion years",
        "Approximately 4 billion years",
        "Approximately 4 billion years",
        "Approximately 4 billion years",
        "Approximately 4.5 billion years",
        "Approximately 5 billion years",
        "Approximately 5 billion years",
        "Approximately 4.6 billion years",
        "Approximately 4.6 billion years",
    };
    const char* wrongAnswer5[9] = {
        "Hydrogen(80 %) and helium (20 %)",
        "Primarily gases",
        "Primarily carbon dioxide (95%) with traces of nitrogen",
        "Primarily nitrogen and oxygen",
        "Primarily iron and nickel",
        "Primarily hydrogen (70%) and helium (30%)",
        "Primarily helium (96.3%), hydrogen (3.7%)",
        "Primarily hydrogen (85%), helium (10%), methane (5%)",
        "Primarily hydrogen (82%), helium (17%), methane (1%)",
    };
    const char* wrongAnswer6[9] = {
        "Converting helium into hydrogen",
        "Primarily generates heat internally",
        "Primarily releases radiation",
        "Mainly nuclear fusion",
        "Primarily produces methane",
        "Absorbs sunlight for energy production",
        "Primarily absorbs sunlight",
        "Absorbs and releases sunlight",
        "Absorbs and releases sunlight",
    };

    int infoCounter = 0;


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
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else { 

                    if (badGuysLeftX < 0) {
                        badGuysLeftX += badGuysSpeed;
                    }
                    DrawTexture(badGuysLeft, badGuysLeftX, 0, RAYWHITE);
                    if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
                        badGuysRightX -= badGuysSpeed;
                    }
                    DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);

                    if (!dialogShown2) {
                        DrawTextEx(Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);

                        if (!dialogShown) {
                            DrawTextEx(Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
                            DrawTextEx(Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
                            if (IsKeyPressed(KEY_ENTER)) {
                                dialogShown = true;
                            }
                        }

                        else if (!dialogShown2) {
                            DrawTextEx(Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);

                            if (IsKeyPressed(KEY_ENTER)) {
                                dialogShown2 = true;
                                dialogShown2 = true;
                            }
                        }

                    };

                    
                    
            }
            break;
        case 1:
            

            DrawTexture(mercury, GetScreenWidth() / 2 - mercury.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Mercury is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 2:
            DrawTexture(venus, GetScreenWidth() / 2 - venus.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Venus is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 3:
            DrawTexture(earth, GetScreenWidth() / 2 - earth.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Earth is! We are back!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 4:
            DrawTexture(mars, GetScreenWidth() / 2 - mars.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Mars is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 5:
            DrawTexture(jupiter, GetScreenWidth() / 2 - jupiter.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Jupiter is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 6:
            DrawTexture(saturn, GetScreenWidth() / 2 - saturn.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Saturn is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 7:
            DrawTexture(uranus, GetScreenWidth() / 2 - uranus.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Uranus is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        case 8:
            DrawTexture(neptune, GetScreenWidth() / 2 - neptune.width / 2, posY, RAYWHITE);
            if (!firstTextShown) {
                DrawTextEx(Poppins, "Wow! Here Neptune is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);

                frameCounter++;
                if (frameCounter > firstTextDuration) {
                    firstTextShown = true;
                    frameCounter = 0;
                }
            }
            else if (!okTextShown) {
                DrawTextEx(Poppins, leftInformation[chosenPlanetIndex], Vector2(120, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, rightInformation[chosenPlanetIndex], Vector2(920, 100), 20, 2, RAYWHITE);
                DrawTextEx(Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 600), 40, 2, BLUE);
                if (IsKeyPressed(KEY_ENTER)) {
                    okTextShown = true;
                }
            }
            else {
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
        
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(rocket);
}
