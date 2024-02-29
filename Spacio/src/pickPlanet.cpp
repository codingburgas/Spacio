#include "pickPlanet.h"
#include "GameState.h"
#include "basicData.h"

// Global variable to store the index of the chosen planet
int chosenPlanetIndex = -1;

void InitPickPlanetWindow()
{
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, NULL, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, NULL, 0);

    basicData.background = LoadTexture("../assets/images/pickPlanetBackground.png");
    pickPlanetData.sun = LoadTexture("../assets/images/objects/sun.png");
    pickPlanetData.mercury = LoadTexture("../assets/images/objects/mercury.png");
    pickPlanetData.venus = LoadTexture("../assets/images/objects/venus.png");
    pickPlanetData.earth = LoadTexture("../assets/images/objects/earth.png");
    pickPlanetData.mars = LoadTexture("../assets/images/objects/mars.png");
    pickPlanetData.jupiter = LoadTexture("../assets/images/objects/jupiter.png");
    pickPlanetData.saturn = LoadTexture("../assets/images/objects/saturn.png");
    pickPlanetData.uranus = LoadTexture("../assets/images/objects/uranus.png");
    pickPlanetData.neptune = LoadTexture("../assets/images/objects/neptune.png");
    pickPlanetData.whichCelestialObject = LoadMusicStream("../assets/audios/whichCelestialObject.mp3");

    basicData.voiceTime = 0.0;
}

// Function to draw celestial objects and handle user clicks
void ObjectsDraw(Texture2D sun, Texture2D mercury, Texture2D venus, Texture2D earth, Texture2D mars, Texture2D jupiter, Texture2D saturn, Texture2D uranus, Texture2D neptune, bool objectClicked[9], bool& madeChoice) {
    for (int i = 0; i < 9; i++) {
        switch (i) {
        case 0: DrawTexture(sun, -10, 250, WHITE); break;
        case 1: DrawTexture(mercury, 345, 420, WHITE); break;
        case 2: DrawTexture(venus, 430, 410, WHITE); break;
        case 3: DrawTexture(earth, 540, 400, WHITE); break;
        case 4: DrawTexture(mars, 670, 405, WHITE); break;
        case 5: DrawTexture(jupiter, 790, 375, WHITE); break;
        case 6: DrawTexture(saturn, 980, 390, WHITE); break;
        case 7: DrawTexture(uranus, 1160, 380, WHITE); break;
        case 8: DrawTexture(neptune, 1280, 380, WHITE); break;
        }

        // Define a rectangle representing the current object's clickable area
        Rectangle objectRect;
        switch (i) {
        case 0: objectRect = { -10, 250, (float)sun.width, (float)sun.height }; break;
        case 1: objectRect = { 345, 420, (float)mercury.width, (float)mercury.height }; break;
        case 2: objectRect = { 430, 410, (float)venus.width, (float)venus.height }; break;
        case 3: objectRect = { 540, 400, (float)earth.width, (float)earth.height }; break;
        case 4: objectRect = { 670, 405, (float)mars.width, (float)mars.height }; break;
        case 5: objectRect = { 790, 375, (float)jupiter.width, (float)jupiter.height }; break;
        case 6: objectRect = { 980, 390, (float)saturn.width, (float)saturn.height }; break;
        case 7: objectRect = { 1160, 380, (float)uranus.width, (float)uranus.height }; break;
        case 8: objectRect = { 1280, 380, (float)neptune.width, (float)neptune.height }; break;
        }

        if (CheckCollisionPointRec(GetMousePosition(), objectRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            objectClicked[i] = true;
            madeChoice = true;
            chosenPlanetIndex = i; // Set the chosen planet index
        }
    }
}

bool loadPickPlanet = true;

// Pick a planet
void pickPlanet(GameState& state) {

    if (loadPickPlanet)
    {
        InitPickPlanetWindow();
        loadPickPlanet = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(pickPlanetData.whichCelestialObject);
    }

        if (basicData.voiceTime < 2.4)
        {
            UpdateMusicStream(pickPlanetData.whichCelestialObject); // Update music
            basicData.voiceTime += GetFrameTime();
        }

    PlayMusicStream(pickPlanetData.whichCelestialObject);

    DrawTexture(basicData.background, 0, 0, RAYWHITE);
    DrawTextEx(basicData.Poppins, "Which celestial object are you visiting today?", Vector2(250, 150), 48, 2, RAYWHITE);

    ObjectsDraw(pickPlanetData.sun, pickPlanetData.mercury, pickPlanetData.venus, pickPlanetData.earth, pickPlanetData.mars, pickPlanetData.jupiter, pickPlanetData.saturn, pickPlanetData.uranus, pickPlanetData.neptune, pickPlanetData.objectClicked, pickPlanetData.madeChoice);

    // If choice made, transition to planet game
    if (pickPlanetData.madeChoice) {
        //planetGame();
    }
}

