#include "userName.h"

void userName() {
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);
    Texture2D background = LoadTexture("../assets/images/userNameBackground.png");


    Rectangle textBox = { 320, 420, 860, 120 };
    const int maxChars = 15;
    char name[maxChars + 1] = "\0";
    int letterCount = 0;
    bool mouseOnText = false;
    int framesCounter = 0;
}