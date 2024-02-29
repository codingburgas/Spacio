#include "userName.h"
#include "mainMenu.h"
#include "basicData.h"
#include <string>

std::string name;

void InitUserNameWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 200, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 200, NULL, 0);
    basicData.background = LoadTexture("../assets/images/userNameBackground.png");
    userNameData.audioUserName = LoadMusicStream("../assets/audios/userName.mp3");

    userNameData.inputBox = { 320, 380, 860, 120 };
    userNameData.maxChars = 15;
    userNameData.letterCount = 0;
    userNameData.framesCounter = 0;
    userNameData.audioSecondUserName = 0;
}

bool load = true;

void userName(GameState& state) {
    if (load)
    {
        InitUserNameWindow();
        load = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(userNameData.audioUserName);
    }

    if (IsMusicStreamPlaying(userNameData.audioUserName) and userNameData.audioSecondUserName < 3.2)
    {
        UpdateMusicStream(userNameData.audioUserName);
        userNameData.audioSecondUserName += GetFrameTime();
    }

    if (CheckCollisionPointRec(GetMousePosition(), userNameData.inputBox)) userNameData.mouseOnText = true;
    else userNameData.mouseOnText = false;

    if (userNameData.mouseOnText) {
        int key = GetKeyPressed();
        if (key > 0) {
        //Checks if key is in ASCII table
            if ((key >= 32) && (key <= 125) && (name.length() < userNameData.maxChars)) {
                name += (char)key;
            }
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (!name.empty()) {
                name.pop_back();
            }
        }
    }


    DrawTexture(basicData.background, 0, 0, RAYWHITE);

    DrawTextEx(basicData.boldPoppins, "What's your name", Vector2(480, 190), 60, 5, RAYWHITE);

    DrawRectangleRec(userNameData.inputBox, GetColor(0x332244ff));
    if (userNameData.mouseOnText) DrawRectangleLines((int)userNameData.inputBox.x, (int)userNameData.inputBox.y, (int)userNameData.inputBox.width, (int)userNameData.inputBox.height, PURPLE);
    else DrawRectangleLines((int)userNameData.inputBox.x, (int)userNameData.inputBox.y, (int)userNameData.inputBox.width, (int)userNameData.inputBox.height, DARKGRAY);

    int textWidth = MeasureText(name.c_str(), 100);
    int textX = userNameData.inputBox.x + (userNameData.inputBox.width - textWidth) / 2;
    int textY = userNameData.inputBox.y + (userNameData.inputBox.height - 100) / 2;

    DrawTextEx(basicData.boldPoppins, name.c_str(), Vector2(textX, textY), 100, 5, RAYWHITE);

    DrawTextEx(basicData.Poppins, "Press Enter to continue", Vector2(445, 580), 50, 5, GetColor(0xBABABAff));
    if (IsKeyPressed(KEY_ENTER))
    {
        state = GameState::CharacterPick;
    }
}
