#include "readyForQuiz.h"

void readyForQuiz()
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/readyBackground.png");
    Texture2D starYes = LoadTexture("../assets/images/starYes.png");
    Texture2D starNo = LoadTexture("../assets/images/starNo.png");

    Rectangle buttonYes = { 850, 170, 300, 300 };
    Rectangle buttonNo = { 850, 500, 300, 300 };

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);
        
        DrawTextEx(boldPoppins, "Are you ready for a quiz?", Vector2(450, 50), 50, 5, WHITE);
        
        DrawTexture(starYes, 800, 150, RAYWHITE);
        DrawTexture(starNo, 800, 450, RAYWHITE);

        DrawRectangleRec(buttonYes, GetColor(0x312b4700));
        DrawRectangleRec(buttonNo, GetColor(0x312b4700));

        if (CheckCollisionPointRec(GetMousePosition(), buttonYes) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            getStation();
        }
        else if (CheckCollisionPointRec(GetMousePosition(), buttonNo) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            getStation();
        }

        EndDrawing();
    }
}