#include "natureScript.h"

void natureScript(std::string userNameStr, bool girlVoice, bool boyVoice)
{
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    Texture2D background = LoadTexture("../assets/images/natureBackground.png");

    const char* script[8] = {
        "It seems like you have chosen\nto learn about the Universe. So\nwhat exactly is the Universe\nyou may ask. We can\nsimply say that it is everything.",
        "The Universe includes all of\nspace, and all the matter and\nenergy that space contains.\nIt even includes time itself\nand, of course, it includes you.",
        "13.8 billion years ago, a brief\ncosmic inflation period\nrapidly expanded the universe,\ninfluencing its observable\nproperties.",
        "The subsequent Big Bang created\na hot particle soup, leading\nto nucleosynthesis and the\nformation of basic elements.",
        "Recombination, 380,000 years\npost-Big Bang, made the universe\ntransparent, producing the\ncosmic microwave background\nradiation.",
        "After recombination, a dark age\nensued, followed by the\nformation of the first stars in\ncooler regions.",
        "Their light initiated\nreionization, breaking down\nhydrogen atoms and rendering\nthe universe transparent.",
        "Currently, dark energy accelerates\nthe universe's expansion,\nchallenging earlier beliefs and\nprompting ongoing research for\nnew insights into its perpetual\ngrowth."
    };

    const char* boyAstronauts[8] = { "../assets/images/astronaut.png", "../assets/images/goodJobAstronaut.png", "../assets/images/astronaut.png", "../assets/images/goodJobAstronaut.png", "../assets/images/astronaut.png", "../assets/images/goodJobAstronaut.png", "../assets/images/astronaut.png", "../assets/images/goodJobAstronaut.png" };
    const char* girlAstronauts[8] = { "../assets/images/goodJobGirlAstronaut.png", "../assets/images/girlAstronautSure.png", "../assets/images/goodJobGirlAstronaut.png", "../assets/images/girlAstronautSure.png", "../assets/images/goodJobGirlAstronaut.png", "../assets/images/girlAstronautSure.png", "../assets/images/goodJobGirlAstronaut.png", "../assets/images/girlAstronautSure.png" };

    Texture2D images[sizeof(boyAstronauts) / sizeof(boyAstronauts[0])];
    Texture2D imagesGirl[sizeof(girlAstronauts) / sizeof(girlAstronauts[0])];

    for (int i = 0; i < sizeof(boyAstronauts) / sizeof(boyAstronauts[0]); i++) {
        images[i] = LoadTexture(boyAstronauts[i]);
    }

    for (int i = 0; i < sizeof(girlAstronauts) / sizeof(girlAstronauts[0]); i++) {
        imagesGirl[i] = LoadTexture(girlAstronauts[i]);
    }

    int counter = 0;
    int current = 0;

    SetTextLineSpacing(45);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, RAYWHITE);

        if (boyVoice) DrawTexture(images[current], 100, 250, WHITE);
        if (girlVoice) DrawTexture(imagesGirl[current], 60, 250, WHITE);

        DrawTextEx(boldPoppins, script[counter], Vector2{ 665, 400 }, 40, 5, WHITE);
        DrawTextEx(boldPoppins, "Press Enter to continue!", Vector2{ 900, 800 }, 40, 5, DARKGRAY);

        if (IsKeyPressed(KEY_ENTER))
        {
            counter++;
            current = (current + 1) % (sizeof(images) / sizeof(images[0]));
        }

        if (counter == 8)
        {
            readyForQuiz(userNameStr, girlVoice, boyVoice);
            break;

        }


        EndDrawing();
    }

    for (int i = 0; i < sizeof(images) / sizeof(images[0]); i++) {
        UnloadTexture(images[i]);
    }

}