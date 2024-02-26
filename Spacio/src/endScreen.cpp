#include "endScreen.h"

void endScreen(std::string userNameStr, bool girlVoice, bool boyVoice) {
    // Load fonts and textures
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/endScreenBg.png");
    Texture2D boyAstronaut = LoadTexture("../assets/images/goodJobAstronaut.png");
    Texture2D girlAstronaut = LoadTexture("../assets/images/goodJobGirlAstronaut.png");

    // Load music streams
    Music girl = LoadMusicStream("../assets/audios/greatJobFemale.mp3");
    Music boy = LoadMusicStream("../assets/audios/greatJobMale.mp3");

    float audioTime = 0.0;
    while (!WindowShouldClose())
    {

        BeginDrawing();

        // Play music streams based on chosen character
        if (girlVoice)
        {
            PlayMusicStream(girl);
            if (IsMusicStreamPlaying(girl) and audioTime <= 2.7)
            {
                UpdateMusicStream(girl);
                audioTime += GetFrameTime();
            }
        }
        else if (boyVoice)
        {
            PlayMusicStream(boy);
            if (IsMusicStreamPlaying(boy) and audioTime <= 2.7)
            {
                UpdateMusicStream(boy);
                audioTime += GetFrameTime();
            }
        }

        // Draw textures and text
        DrawTexture(background, 0, 0, RAYWHITE);
        if(boyVoice) DrawTexture(boyAstronaut, 740, 222, RAYWHITE);
        if(girlVoice) DrawTexture(girlAstronaut, 740, 222, RAYWHITE);

        std::string message = "Good job " + userNameStr + ", you did really great!";
        DrawTextEx(boldPoppins, message.c_str(), Vector2(150, 114), 55, 5, WHITE);
        DrawTextEx(Poppins, "Press Space to return home", Vector2(150, 470), 40, 5, GRAY);

        ClearBackground(RAYWHITE);

        EndDrawing();

        // Check for space key press to continue
        if (IsKeyPressed(KEY_SPACE))
        {
            spaceShip(userNameStr, girlVoice, boyVoice);
            break;
        }
    }
    StopMusicStream(girl);
    StopMusicStream(boy);
}