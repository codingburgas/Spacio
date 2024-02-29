//#include "planetGame.h"
//#include "basicData.h"
//#include<iostream>
//
//
//int wonOrLostGame = 0;
//
//void InitPlanetGameWindow()
//{
//    basicData.background = LoadTexture("../assets/images/spaceGamebasicData.background.png");
//    planetGameData.left = { 120, 500, 520, 94 };
//    planetGameData.right = { 800, 500, 520, 94 };
//    planetGameData.rocket = LoadTexture("../assets/images/rocket.png");
//    planetGameData.badGuysLeft = LoadTexture("../assets/images/badGuysLeft.png");
//    planetGameData.badGuysRight = LoadTexture("../assets/images/badGuysRight.png");
//
//    planetGameData.sun = LoadTexture("../assets/images/objects/sun.png");
//    planetGameData.mercury = LoadTexture("../assets/images/objects/mercury.png");
//    planetGameData.venus = LoadTexture("../assets/images/objects/venus.png");
//    planetGameData.earth = LoadTexture("../assets/images/objects/earth.png");
//    planetGameData.mars = LoadTexture("../assets/images/objects/mars.png");
//    planetGameData.jupiter = LoadTexture("../assets/images/objects/jupiter.png");
//    planetGameData.saturn = LoadTexture("../assets/images/objects/saturn.png");
//    planetGameData.uranus = LoadTexture("../assets/images/objects/uranus.png");
//    planetGameData.neptune = LoadTexture("../assets/images/objects/neptune.png");
//
//    planetGameData.starsRocket[0] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsRocket[1] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsRocket[2] = LoadTexture("../assets/images/star.png");
//
//    planetGameData.starsBadGuys[0] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsBadGuys[1] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsBadGuys[2] = LoadTexture("../assets/images/star.png");
//
//    planetGameData.starsRocket[0] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsRocket[1] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsRocket[2] = LoadTexture("../assets/images/star.png");
//
//    planetGameData.starsBadGuys[0] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsBadGuys[1] = LoadTexture("../assets/images/star.png");
//    planetGameData.starsBadGuys[2] = LoadTexture("../assets/images/star.png");
//
//    planetGameData.deadStar = LoadTexture("../assets/images/deadStar.png");
//    planetGameData.fireLeft = LoadTexture("../assets/images/fireLeft.png");
//    planetGameData.fireRight = LoadTexture("../assets/images/fireRight.png");
//    planetGameData.fireLeftWin = LoadTexture("../assets/images/fireLeftWin.png");
//    planetGameData.fireRightWin = LoadTexture("../assets/images/fireRightWin.png");
//
//    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
//    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);
//
//    planetGameData.rocketY = GetScreenHeight();
//    planetGameData.badGuysLeftX = 0 - planetGameData.badGuysLeft.width;
//    planetGameData.badGuysRightX = GetScreenWidth();
//    planetGameData.badGuysSpeed = 5;
//    planetGameData.firstTextDuration = 120;
//    planetGameData.frameCounter = 0;
//    planetGameData.posY = (GetScreenHeight() - planetGameData.mercury.height) / 5;
//    planetGameData.wrongAnswerCounter = 0;
//    planetGameData.rightAnswerCounter = 0;
//    planetGameData.currentQuestionIndex = 0;
//    planetGameData.stoppingY = 800;
//
//}
//
//// Function to update stars based on correct or wrong answers
//void checkStars(bool correctAnswer, bool wrongAnswer, int wrongAnswerCounter, int rightAnswerCounter, Texture2D starsRocket[], Texture2D starsBadGuys[], Texture2D deadStar, Texture2D fireLeft, Texture2D fireRight, Texture2D fireLeftWin, Texture2D fireRightWin) {
//    if (wrongAnswer) {
//        // Update starsRocket based on the number of wrong answers
//        if (wrongAnswerCounter == 1) {
//            starsRocket[0] = deadStar;
//        }
//
//        if (wrongAnswerCounter == 2) {
//            starsRocket[1] = deadStar;
//        }
//
//        if (wrongAnswerCounter == 3) {
//            starsRocket[2] = deadStar;
//        }
//
//        // If the answer is correct, update stars for the intruders
//        if (correctAnswer) {
//            // Update starsBadGuys based on the number of right answers
//            if (rightAnswerCounter == 1) {
//                starsBadGuys[0] = deadStar;
//            }
//
//            if (rightAnswerCounter == 2) {
//                starsBadGuys[1] = deadStar;
//            }
//
//            if (rightAnswerCounter == 3) {
//                starsBadGuys[2] = deadStar;
//            }
//        }
//    }
//}
//// Main game function
//void planetGame() {
//    
//    SetTextLineSpacing(30);
//
//    int infoCounter = 0;
//    // Add sound effects and voice-overs
//    Sound haltInturder = LoadSound("../assets/audios/haltIntruder.mp3");
//    Sound youNeedToAnswer = LoadSound("../assets/audios/youNeedToAnswerSomeQuestions.mp3");
//    Sound captainSpeaking = LoadSound("../assets/audios/captainSpeaking.mp3");
//    // Main game loop
//    while (!WindowShouldClose()) {
//
//        DrawTexture(basicData.background, 0, 0, RAYWHITE);
//        // Move the rocket upwards if it's above the stopping Y position
//        if (planetGameData.rocketY > planetGameData.stoppingY) {
//
//            planetGameData.rocketY -= 1;
//
//        }
//        // Draw the rocket texture
//        DrawTextureEx(planetGameData.rocket, Vector2(GetScreenWidth() / 2 - planetGameData.rocket.width / 2, planetGameData.rocketY), 270, 1, RAYWHITE);
//
//
//        switch (chosenPlanetIndex) {
//
//            //The sun
//
//        case 0:
//            // Draw the Sun texture
//            DrawTexture(planetGameData.sun, GetScreenWidth() / 2 - planetGameData.sun.width / 2, 0, RAYWHITE);
//            // Draw first dialog
//            if (!planetGameData.firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here the sun is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                planetGameData.frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (planetGameData.frameCounter > planetGameData.firstTextDuration) {
//                    planetGameData.firstTextShown = true;
//                    planetGameData.frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!planetGameData.okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, planetGameData.leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, planetGameData.rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    planetGameData.okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (planetGameData.badGuysLeftX < 0) {
//
//                    planetGameData.badGuysLeftX += planetGameData.badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, planetGameData.badGuysLeftX, 0, RAYWHITE);
//
//                if (planetGameData.badGuysRightX > GetScreenWidth() - planetGameData.badGuysRight.width) {
//
//                    planetGameData.badGuysRightX -= planetGameData.badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysRight, planetGameData.badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//                   
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                      // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//                        }
//                    }
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    planetGameData.quizGame = true;
//
//                }
//
//                if (planetGameData.quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(planetGameData.starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (planetGameData.currentQuestionIndex) {
//                     //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, planetGameData.firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//
//                                planetGameData.wrongAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                                planetGameData.currentQuestionIndex++;
//
//                            }
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//
//                                planetGameData.rightAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                                planetGameData.currentQuestionIndex++;
//
//                            }
//
//                        }
//
//
//
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, planetGameData.secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, planetGameData.forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, planetGameData.fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                        break;
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Mercury
//
//        case 1:
//            // Draw the Mercury texture
//                DrawTexture(planetGameData.mercury, GetScreenWidth() / 2 - planetGameData.mercury.width / 2, planetGameData.posY, RAYWHITE);
//                // Draw first dialog
//            if (!planetGameData.firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Mercury is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                planetGameData.frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (planetGameData.frameCounter > planetGameData.firstTextDuration) {
//                    planetGameData.firstTextShown = true;
//                    planetGameData.frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!planetGameData.okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, planetGameData.leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, planetGameData.rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    planetGameData.okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (planetGameData.badGuysLeftX < 0) {
//
//                    planetGameData.badGuysLeftX += planetGameData.badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, planetGameData.badGuysLeftX, 0, RAYWHITE);
//
//                if (planetGameData.badGuysRightX > GetScreenWidth() - planetGameData.badGuysRight.width) {
//
//                    planetGameData.badGuysRightX -= planetGameData.badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysRight, planetGameData.badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    planetGameData.quizGame = true;
//
//                }
//
//                if (planetGameData.quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(planetGameData.starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(planetGameData.starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (planetGameData.currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, planetGameData.firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//
//                                planetGameData.wrongAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                planetGameData.currentQuestionIndex++;
//
//                            }
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//
//                                planetGameData.rightAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                planetGameData.currentQuestionIndex++;
//
//                            }
//
//                        }
//
//
//
//                        break;
//
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, planetGameData.secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, planetGameData.forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, planetGameData.fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(basicData.boldPoppins, planetGameData.rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                planetGameData.wrongAnswer = true;
//                                planetGameData.wrongAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                planetGameData.correctAnswer = true;
//                                planetGameData.rightAnswerCounter++;
//                                planetGameData.currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                        break;
//
//
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Venus
//
//        case 2:
//            // Draw the Venus texture
//            DrawTexture(planetGameData.venus, GetScreenWidth() / 2 - planetGameData.venus.width / 2, planetGameData.posY, RAYWHITE);
//            // Draw first dialog
//            if (!planetGameData.firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Venus is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                planetGameData.frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (planetGameData.frameCounter > planetGameData.firstTextDuration) {
//                    planetGameData.firstTextShown = true;
//                    planetGameData.frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!planetGameData.okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, planetGameData.leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, planetGameData.rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    planetGameData.okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (planetGameData.badGuysLeftX < 0) {
//
//                    planetGameData.badGuysLeftX += planetGameData.badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, planetGameData.badGuysLeftX, 0, RAYWHITE);
//
//                if (planetGameData.badGuysRightX > GetScreenWidth() - planetGameData.badGuysRight.width) {
//
//                    planetGameData.badGuysRightX -= planetGameData.badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysRight, planetGameData.badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//
//                                wrongAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                                currentQuestionIndex++;
//
//                            }
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//
//                                rightAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                                currentQuestionIndex++;
//
//                            }
//
//                        }
//
//
//
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Earth
//
//        case 3:
//            // Draw the Earth texture
//            DrawTexture(earth, GetScreenWidth() / 2 - earth.width / 2, posY, RAYWHITE);
//            // Draw first dialog
//            if (!firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Earth is! We are back!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (frameCounter > firstTextDuration) {
//                    firstTextShown = true;
//                    frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (badGuysLeftX < 0) {
//
//                    badGuysLeftX += badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysLeft, badGuysLeftX, 0, RAYWHITE);
//
//                if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
//
//                    badGuysRightX -= badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//
//                                wrongAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                                currentQuestionIndex++;
//
//                            }
//
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//
//                                rightAnswerCounter++;
//
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                                currentQuestionIndex++;
//
//                            }
//
//                        }
//
//
//
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//
//                    }
//
//                }
//
//            }
//            break;
//                //Mars
//
//        case 4:
//            // Draw the Mars texture
//            DrawTexture(mars, GetScreenWidth() / 2 - mars.width / 2, posY, RAYWHITE);
//            // Draw first dialog
//            if (!firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Mars is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (frameCounter > firstTextDuration) {
//                    firstTextShown = true;
//                    frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (badGuysLeftX < 0) {
//
//                    badGuysLeftX += badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, badGuysLeftX, 0, RAYWHITE);
//
//                if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
//
//                    badGuysRightX -= badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                        }
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Jupiter
//
//        case 5:
//            // Draw the Jupiter texture
//            DrawTexture(jupiter, GetScreenWidth() / 2 - jupiter.width / 2, posY, RAYWHITE);
//            // Draw first dialog
//            if (!firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Jupiter is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (frameCounter > firstTextDuration) {
//                    firstTextShown = true;
//                    frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (badGuysLeftX < 0) {
//
//                    badGuysLeftX += badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, badGuysLeftX, 0, RAYWHITE);
//
//                if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
//
//                    badGuysRightX -= badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                        }
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Saturn
//
//        case 6:
//            // Draw the Saturn texture
//            DrawTexture(saturn, GetScreenWidth() / 2 - saturn.width / 2, posY, RAYWHITE);
//            // Draw first dialog
//            if (!firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Saturn is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (frameCounter > firstTextDuration) {
//                    firstTextShown = true;
//                    frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (badGuysLeftX < 0) {
//
//                    badGuysLeftX += badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, badGuysLeftX, 0, RAYWHITE);
//
//                if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
//
//                    badGuysRightX -= badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                        }
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Uranus
//
//        case 7:
//            // Draw the Uranus texture
//            DrawTexture(uranus, GetScreenWidth() / 2 - uranus.width / 2, posY, RAYWHITE);
//            // Draw first dialog
//            if (!firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Uranus is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (frameCounter > firstTextDuration) {
//                    firstTextShown = true;
//                    frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (badGuysLeftX < 0) {
//
//                    badGuysLeftX += badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, badGuysLeftX, 0, RAYWHITE);
//
//                if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
//
//                    badGuysRightX -= badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                        }
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//                    }
//
//                }
//
//            }
//
//            break;
//
//            //Neptune
//
//        case 8:
//            // Draw the Neptune texture
//            DrawTexture(neptune, GetScreenWidth() / 2 - neptune.width / 2, posY, RAYWHITE);
//            // Draw first dialog
//            if (!firstTextShown) {
//
//                DrawTextEx(basicData.Poppins, "Wow! Here Neptune is! We are here!", Vector2(420, 500), 48, 2, RAYWHITE);
//                PlaySound(captainSpeaking);
//                frameCounter++;
//                // if statement, responsible for the rocket's movement
//                if (frameCounter > firstTextDuration) {
//                    firstTextShown = true;
//                    frameCounter = 0;
//                }
//            }
//            // Draw second dialog
//            else if (!okTextShown) {
//                // Draw the information around the planet
//                DrawTextEx(basicData.Poppins, leftInformation[chosenPlanetIndex], Vector2(100, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, rightInformation[chosenPlanetIndex], Vector2(900, 100), 30, 2, RAYWHITE);
//                DrawTextEx(basicData.Poppins, "...Captain speaking. You must\n"" learn this information. \n""When you are done, press ENTER.\n""Over.", Vector2(120, 700), 40, 2, BLUE);
//                PlaySound(haltInturder);
//                if (IsKeyPressed(KEY_ENTER)) {
//                    okTextShown = true;
//                }
//            }
//
//            else {
//                // Display the Intruders with an animation
//                if (badGuysLeftX < 0) {
//
//                    badGuysLeftX += badGuysSpeed;
//
//                }
//
//                DrawTexture(planetGameData.badGuysLeft, planetGameData.badGuysLeftX, 0, RAYWHITE);
//
//                if (badGuysRightX > GetScreenWidth() - badGuysRight.width) {
//
//                    badGuysRightX -= badGuysSpeed;
//
//                }
//
//                DrawTexture(badGuysRight, badGuysRightX, 0, RAYWHITE);
//                // if statement, responsible for the "press ENTER to continue" to be displayed for a certain amount of time
//                if (!planetGameData.dialogShown2) {
//
//                    DrawTextEx(basicData.Poppins, "press ENTER to continue", Vector2(120, 840), 30, 2, BLUE);
//                    // Display dialog
//                    if (!planetGameData.planetGameData.dialogShown) {
//
//                        DrawTextEx(basicData.Poppins, "Oh no! ", Vector2(520, 550), 48, 2, RAYWHITE);
//                        PlaySound(youNeedToAnswer);
//
//                        DrawTextEx(basicData.Poppins, "Halt, intruder! Prepare to be boarded, probed, and\n""             ... well, you can guess the rest!", Vector2(330, 400), 40, 2, RED);
//                        // Quit displaying dialog if the Enter key is pressed
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.planetGameData.dialogShown = true;
//
//                        }
//
//
//                    }
//                    // Display dialog
//                    else if (!planetGameData.dialogShown2) {
//
//                        DrawTextEx(basicData.Poppins, "You need to answer some questions if you want to survive...", Vector2(230, 400), 40, 2, RED);
//                        // if statement, responsible for the whole dialog piece using enter
//                        if (IsKeyPressed(KEY_ENTER)) {
//
//                            planetGameData.dialogShown2 = true;
//
//
//                        }
//
//                    }
//
//
//                }
//                // Start the quiz game
//                if (IsKeyPressed(KEY_ENTER) && planetGameData.dialogShown2 == true) {
//
//                    quizGame = true;
//
//                }
//
//                if (quizGame) {
//                    // Draw stars representing remaining lives for the rocket and the Intruders
//                    DrawTextureEx(starsRocket[0], Vector2(80, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[1], Vector2(160, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsRocket[2], Vector2(240, 790), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[0], Vector2(880, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[1], Vector2(960, 20), 0, 0.15, RAYWHITE);
//                    DrawTextureEx(starsBadGuys[2], Vector2(1040, 20), 0, 0.15, RAYWHITE);
//
//                    // Questions
//                    switch (currentQuestionIndex) {
//                        //First quetsion
//                    case 0:
//                        // Draw the first question text
//                        DrawTextEx(basicData.Poppins, firstQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer1[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer1[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                                currentQuestionIndex++;
//                            }
//                        }
//                        break;
//                        // Case 1: Second question
//                    case 1:
//                        // Draw the second question text
//                        DrawTextEx(basicData.Poppins, secondQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer2[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer2[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 2: Third question (similar structure as Case 1)
//                    case 2:
//                        // Draw the third question text
//                        DrawTextEx(basicData.Poppins, planetGameData.thirdQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer3[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer3[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                                checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//                            }
//                        }
//
//                        break;
//
//                        // Case 3: Fourth question (similar structure as Case 1)
//                    case 3:
//                        // Draw the fourth question text
//                        DrawTextEx(basicData.Poppins, forthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer4[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer4[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//                        // Case 4: Fifth question (similar structure as Case 1)
//                    case 4:
//                        // Draw the fifth question text
//                        DrawTextEx(basicData.Poppins, fifthQuestion[chosenPlanetIndex], Vector2(230, 400), 40, 2, RED);
//
//                        // Draw rectangles representing answer options and answers
//                        DrawRectangleRec(planetGameData.left, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, wrongAnswer5[chosenPlanetIndex], Vector2(160, 530), 30, 5, WHITE);
//
//                        DrawRectangleRec(planetGameData.right, GetColor(0X2C2C2Cff));
//                        DrawTextEx(boldPoppins, rightAnswer5[chosenPlanetIndex], Vector2(840, 530), 30, 5, WHITE);
//
//                        // Check for mouse button press to select answer
//                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.left)) {
//                                // Mark wrong answer and update counters
//                                wrongAnswer = true;
//                                wrongAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                            if (CheckCollisionPointRec(GetMousePosition(), planetGameData.right)) {
//                                // Mark correct answer and update counters
//                                correctAnswer = true;
//                                rightAnswerCounter++;
//                                currentQuestionIndex++;
//                            }
//                        }
//
//                        // Call checkStars function after handling answers
//                        checkStars(planetGameData.correctAnswer, planetGameData.wrongAnswer, planetGameData.wrongAnswerCounter, planetGameData.rightAnswerCounter, planetGameData.starsRocket, planetGameData.starsBadGuys, planetGameData.deadStar, planetGameData.fireLeft, planetGameData.fireRight, planetGameData.fireLeftWin, planetGameData.fireRightWin);
//
//                        break;
//
//
//                    }
//
//                }
//
//            }
//
//            break;
//
//        }
//
//        if (wrongAnswerCounter == 3) {
//
//            wonOrLostGame = 1;
//            endPlanetGame();
//
//            break;
//
//        }
//
//        if (rightAnswerCounter == 3) {
//
//            wonOrLostGame = 2;
//            endPlanetGame();
//
//            break;
//
//        }
//
//
//        EndDrawing();
//
//    }
//
//
//    UnloadTexture(basicData.background);
//
//    UnloadTexture(rocket);
//    
//}