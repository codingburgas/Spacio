#include "userName.h"
#include <string>
#include <iostream>

void userName(int pick) {
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);
    Texture2D background = LoadTexture("../assets/images/userNameBackground.png");


    Rectangle inputBox = { 320, 380, 860, 120 };
    const int maxChars = 15;
    char name[maxChars + 1] = "\0";
    int letterCount = 0;
    bool mouseOnText = false;
    int framesCounter = 0;

    SetMouseCursor(MOUSE_CURSOR_ARROW);

    while (!WindowShouldClose())
    {
        if (CheckCollisionPointRec(GetMousePosition(), inputBox)) mouseOnText = true;
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

        std::string userNameStr(name);

        BeginDrawing();

        ClearBackground(RAYWHITE);


        DrawText("Test", 190, 200, 20, LIGHTGRAY);
        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTextEx(boldPoppins, "What's your name", Vector2(480, 190), 60, 5, RAYWHITE);

        DrawRectangleRec(inputBox, GetColor(0x332244ff));
        if (mouseOnText) DrawRectangleLines((int)inputBox.x, (int)inputBox.y, (int)inputBox.width, (int)inputBox.height, PURPLE);
        else DrawRectangleLines((int)inputBox.x, (int)inputBox.y, (int)inputBox.width, (int)inputBox.height, DARKGRAY);

        int textWidth = MeasureText(name, 100);
        int textX = inputBox.x + (inputBox.width - textWidth) / 2;
        int textY = inputBox.y + (inputBox.height - 100) / 2;

        DrawTextEx(boldPoppins, name, Vector2(textX, textY), 100, 5, RAYWHITE);

        DrawTextEx(Poppins, "Press Enter to continue", Vector2(445, 580), 50, 5, GetColor(0xBABABAff));

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER))
        {
            if (pick == 1)
            {
                getStation();
                break;
            }
            else if (pick == 2)
            {

                particlePick(userNameStr);

                break;
            }
            else if (pick == 3)
            {

                natureScript();
                
                break;
            }
        }
    }
}