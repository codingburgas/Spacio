#include "intro.h"

void intro() {
    BeginDrawing();

    Image background = LoadImage("../assets/images/introBackground.png");
    Texture2D backgroundIntro = LoadTextureFromImage(background);
    ClearBackground(RAYWHITE);

    DrawTexture(backgroundIntro, 0, 0, WHITE);

    EndDrawing();
}