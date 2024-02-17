#include "getStation.h"
#include <iostream>

void getStation() {
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);
    Texture2D background = LoadTexture("../assets/images/getStationBackground.png");


    Rectangle textBox = { 320, 420, 860, 120 };
    const int maxChars = 15;
    char name[maxChars + 1] = "\0";
    int letterCount = 0;
    bool mouseOnText = false;
    int framesCounter = 0;

    while (!WindowShouldClose()) {

        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText) {

            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (letterCount < maxChars)) {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0';
                    letterCount++;
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTextEx(boldPoppins, "Which station are you launching from?", Vector2{ 280, 260 }, 50, 5, WHITE);


        DrawRectangleRec(textBox, LIGHTGRAY);
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, PURPLE);
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        int textWidth = MeasureText(name, 100);
        int textX = textBox.x + (textBox.width - textWidth) / 2;
        int textY = textBox.y + (textBox.height - 100) / 2;

        DrawText(name, textX, textY, 100, DARKPURPLE);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, maxChars), 320, 550, 20, DARKGRAY);
        DrawTextEx(boldPoppins, "Press Enter to continue", Vector2{ 480, 660 }, 50, 5, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER))
        {
            pickPlanet();
            break;
        }
    }
}