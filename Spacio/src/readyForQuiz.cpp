#include "readyForQuiz.h"
int pick;

void Cursor(Rectangle buttonYes, Rectangle buttonNo)
{
    if (CheckCollisionPointRec(GetMousePosition(), buttonYes)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else SetMouseCursor(MOUSE_CURSOR_ARROW);

    if (CheckCollisionPointRec(GetMousePosition(), buttonNo)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
}


void readyForQuiz(std::string userNameStr, bool girlVoice, bool boyVoice)
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/readyBackground.png");
    Texture2D girlAstronaut = LoadTexture("../assets/images/readyForQuizGirlAstronaut.png");
    Texture2D boyAstronaut = LoadTexture("../assets/images/astronaut.png");

    Texture2D starYes = LoadTexture("../assets/images/starYes.png");
    Texture2D starNo = LoadTexture("../assets/images/starNo.png");

    Rectangle buttonYes = { 850, 170, 300, 300 };
    Rectangle buttonNo = { 850, 500, 300, 300 };

    Music audioBoy = LoadMusicStream("../assets/audios/readyMale.mp3");
    PlayMusicStream(audioBoy);

    Music audioGirl = LoadMusicStream("../assets/audios/readyFemale.mp3");
    PlayMusicStream(audioGirl);

    float audioSecond1 = GetMusicTimeLength(audioBoy);
    float audioSecond2 = GetMusicTimeLength(audioGirl);
    float audioTime = 0.0;

    while (!WindowShouldClose())
    {

        BeginDrawing(); 

                if (boyVoice)
                {
                    if (IsMusicStreamPlaying(audioBoy) and audioTime < 3.2)
                    {
                        UpdateMusicStream(audioBoy);
                        audioTime += GetFrameTime();
                    }
                }

                if (girlVoice)
                {
                    if (IsMusicStreamPlaying(audioGirl) and audioTime < 3.5)
                    {
                        UpdateMusicStream(audioGirl);
                        audioTime += GetFrameTime();
                    }
                }

                ClearBackground(RAYWHITE);

                DrawTexture(background, 0, 0, RAYWHITE);

                DrawTextEx(boldPoppins, "Are you ready for a quiz?", Vector2(450, 50), 50, 5, WHITE);

                if (boyVoice) DrawTexture(boyAstronaut, 50, 250, RAYWHITE);
                if (girlVoice) DrawTexture(girlAstronaut, 50, 250, RAYWHITE);

                DrawTexture(starYes, 800, 150, RAYWHITE);
                DrawTexture(starNo, 800, 450, RAYWHITE);

                DrawRectangleRec(buttonYes, GetColor(0x312b4700));
                DrawRectangleRec(buttonNo, GetColor(0x312b4700));

                void Cursor(Rectangle buttonYes, Rectangle buttonNo);

                if (CheckCollisionPointRec(GetMousePosition(), buttonYes) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    gameQuiz(userNameStr, girlVoice, boyVoice);
                    break;
                }
                else if (CheckCollisionPointRec(GetMousePosition(), buttonNo) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    spaceShip(userNameStr, girlVoice, boyVoice);
                    break;
                }

                EndDrawing();
            }
        }
