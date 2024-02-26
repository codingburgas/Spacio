#include "pickPlanet.h"

// Global variable to store the index of the chosen planet
int chosenPlanetIndex = -1;

// Function to draw celestial objects on the screen and handle user clicks
void ObjectsDraw(Texture2D sun, Texture2D mercury, Texture2D venus, Texture2D earth, Texture2D mars, Texture2D jupiter, Texture2D saturn, Texture2D uranus, Texture2D neptune, bool objectClicked[9], bool& madeChoice) {
    // Loop through each celestial object
    for (int i = 0; i < 9; i++) {
        // Draw the celestial object at its designated position
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

        // Check if the mouse is hovering over the current object and if left mouse button is pressed
        if (CheckCollisionPointRec(GetMousePosition(), objectRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            objectClicked[i] = true;
            madeChoice = true;
            chosenPlanetIndex = i; // Set the chosen planet index
        }
    }
}

// Function to handle picking a planet
void pickPlanet() {
    // Load textures and fonts
    Texture2D sun = LoadTexture("../assets/images/objects/sun.png");
    Texture2D mercury = LoadTexture("../assets/images/objects/mercury.png");
    Texture2D venus = LoadTexture("../assets/images/objects/venus.png");
    Texture2D earth = LoadTexture("../assets/images/objects/earth.png");
    Texture2D mars = LoadTexture("../assets/images/objects/mars.png");
    Texture2D jupiter = LoadTexture("../assets/images/objects/jupiter.png");
    Texture2D saturn = LoadTexture("../assets/images/objects/saturn.png");
    Texture2D uranus = LoadTexture("../assets/images/objects/uranus.png");
    Texture2D neptune = LoadTexture("../assets/images/objects/neptune.png");
    Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
    Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

    // Array to track clicked objects and flag for indicating choice made
    bool objectClicked[9] = { false };
    bool madeChoice = false;

    // Load background image and sound
    Texture2D background = LoadTexture("../assets/images/pickPlanetBackground.png");
    Sound whichCelestialObject = LoadSound("../assets/audios/whichCelestialObject.mp3");
    PlaySound(whichCelestialObject);

    // Main loop to pick a planet
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw background and instruction text
        DrawTexture(background, 0, 0, RAYWHITE);
        DrawTextEx(Poppins, "Which celestial object are you visiting today?", Vector2(250, 150), 48, 2, RAYWHITE);

        // Draw celestial objects and handle user clicks
        ObjectsDraw(sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, objectClicked, madeChoice);

        // If choice made, transition to planet game and exit loop
        if (madeChoice) {
            planetGame();
            break;
        }

        EndDrawing();
    }
}

