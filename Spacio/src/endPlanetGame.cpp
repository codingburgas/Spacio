//#include "endPlanetGame.h"
//
//// Function to display end game screen and handle user interaction
//void endPlanetGame() {
//    // Define rectangles for try again and quit buttons
//    Rectangle tryAgain{ 520, 500, 280, 94 };
//    Rectangle quit = { 520, 650, 280, 94 };
//
//    // Load sounds and fonts
//    Sound youWon = LoadSound("../assets/audios/youWon.mp3");
//    Sound youLost = LoadSound("../assets/audios/youLost.mp3");
//    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
//    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);
//
//    // Load background texture
//    Texture2D background = LoadTexture("../assets/images/pickPlanetBackground.png");
//
//    // Play appropriate sound based on game outcome
//    if (wonOrLostGame == 1) {
//        PlaySound(youLost);
//    }
//    if (wonOrLostGame == 2) {
//        PlaySound(youWon);
//    }
//
//    // Main loop for end game screen
//    while (!WindowShouldClose()) {
//        BeginDrawing();
//        ClearBackground(RAYWHITE);
//        DrawTexture(background, 0, 0, RAYWHITE);
//
//        // Display appropriate text based on game outcome
//        if (wonOrLostGame == 1) {
//            DrawTextEx(Poppins, "You lost! Would you like to try again?", Vector2(350, 150), 60, 2, RAYWHITE);
//        }
//        if (wonOrLostGame == 2) {
//            DrawTextEx(Poppins, "You won! Would you like to try again?", Vector2(350, 150), 60, 2, RAYWHITE);
//        }
//
//        // Draw try again and quit buttons
//        DrawRectangleRec(tryAgain, GetColor(0X2C2C2Cff));
//        DrawTextEx(boldPoppins, "Try Again", Vector2(570, 530), 37, 5, WHITE);
//        DrawRectangleRec(quit, GetColor(0X2C2C2Cff));
//        DrawTextEx(boldPoppins, "Quit", Vector2(610, 680), 37, 5, WHITE);
//
//        // Check for mouse clicks on buttons
//        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//            if (CheckCollisionPointRec(GetMousePosition(), tryAgain)) {
//                // Retry the planet picking game
//                //pickPlanet();
//                break;
//            }
//            if (CheckCollisionPointRec(GetMousePosition(), quit)) {
//                // Quit the game
//                break;
//            }
//        }
//
//        EndDrawing();
//    }
//}
//
//
