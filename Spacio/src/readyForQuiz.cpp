#include "readyForQuiz.h"

void Quiz()
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/readyBackground.png");
    Texture2D starYes = LoadTexture("../assets/images/starYes.png");
    Texture2D starNo = LoadTexture("../assets/images/starNo.png");

    Rectangle buttonYes = { 800, 150, 384, 414 };
    Rectangle buttonNo = { 800, 450, 384, 414 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTexture(starYes, 800, 150, RAYWHITE);
        DrawTexture(starNo, 800, 450, RAYWHITE);

        DrawRectangleRec(buttonYes, GetColor(0x312b4700));
        DrawRectangleRec(buttonNo, GetColor(0x312b4700));

        void mouseCursorOnRectangle(Rectangle buttonYes, Rectangle buttonNo);

        DrawTextEx(boldPoppins, "Are you ready for a quiz?", Vector2(450, 50), 50, 5, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), buttonYes)) {
            getStation();
        }
        else if (CheckCollisionPointRec(GetMousePosition(), buttonNo)) {
            getStation();
        }

        EndDrawing();
    }
}