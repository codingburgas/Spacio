#include "chooseLearningStyle.h"
//Check if cursor is on rectangle
bool cursorOnRectangle(Rectangle rectangle) {
    if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
        return true;
    }

    return false;
}
// Set mouse cursor based on collision
void mouseCursorLearningStyle(Rectangle reading, Rectangle playing)
{
    if (CheckCollisionPointRec(GetMousePosition(), reading)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), playing)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}

void chooseLearningStyle(bool boyVoice, bool girlVoice, std::string userNameStr) {
    // Load textures, fonts, and music streams
	Texture2D background = LoadTexture("../assets/images/chooseLearningStyleBg.png");

    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

    Rectangle reading = { 283, 302, 295, 295 };
    Rectangle playing = { 830,304 ,295 ,295 };

    Music girl = LoadMusicStream("../assets/audios/learningStyleFemale.mp3");
    Music boy = LoadMusicStream("../assets/audios/learningStyleMale.mp3");

    float girlSecond = GetMusicTimeLength(girl);
    float boySecond = GetMusicTimeLength(boy);
    float audioTime = 0.0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        // Play music streams based on chosen character
        if (girlVoice)
        {
            PlayMusicStream(girl);
            if (IsMusicStreamPlaying(girl) and audioTime < girlSecond)
            {
                UpdateMusicStream(girl);
                audioTime += GetFrameTime();
            }
        }
        else if (boyVoice)
        {
            PlayMusicStream(boy);
            if (IsMusicStreamPlaying(boy) and audioTime < boySecond)
            {
                UpdateMusicStream(boy);
                audioTime += GetFrameTime();
            }
        }

        DrawTexture(background, 0, 0, RAYWHITE);

        DrawTextEx(boldPoppins, "How do you want to learn?", Vector2(336, 137), 64, 5, WHITE);
        DrawTextEx(boldPoppins, "By reading", Vector2(371, 605), 32, 5, WHITE);
        DrawTextEx(boldPoppins, "By playing", Vector2(909, 605), 32, 5, WHITE);

        mouseCursorLearningStyle(reading, playing);
        //Function call to set the mouse cursor
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (cursorOnRectangle(reading)) {
                questions(boyVoice, girlVoice, userNameStr);
                break;
            }
            if (cursorOnRectangle(playing)) {
                spaceShip(userNameStr, girlVoice, boyVoice);
                break;
            }
        }

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    StopMusicStream(girl);
    StopMusicStream(boy);
}