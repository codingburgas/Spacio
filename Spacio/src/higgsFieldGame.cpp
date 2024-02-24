#include "higgsFieldGame.h"

void HiggsFieldGame(bool hasMass) {
	Texture2D background = LoadTexture("../assets/images/higgsfieldBg.png");
	Texture2D particle = LoadTexture("../assets/images/particle.png");



	Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
	Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 500, 0, 0);

	const int verticalStep = 84;
	int horizontalStep = 16;
	const int lowest = 707;
	const int highest = 539;
	const int leftStart = -1272;
	const int rightEnd = -60;
	int particleVertical = 707;
	int particleHorizontal = -1272;

	while (!WindowShouldClose())
	{

		BeginDrawing();

		DrawTexture(background, 0, 0, RAYWHITE);

		if (IsKeyPressed(KEY_UP) && particleVertical > highest) {
			particleVertical -= verticalStep;
			horizontalStep /= 2;
		}
		if (IsKeyPressed(KEY_DOWN) && particleVertical < lowest) {
			particleVertical += verticalStep;
			horizontalStep *= 2;
		}

		if (particleHorizontal > rightEnd || particleHorizontal < leftStart) {
			horizontalStep = -horizontalStep;
		}

		particleHorizontal += horizontalStep;

		DrawTexture(particle, particleHorizontal, particleVertical, RAYWHITE);

		int position = (lowest - particleVertical) / verticalStep;

		std::string massText = "Mass: ";
		std::string speedText = "Speed: ";
		std::string infoText;

		switch (position) {
		case 0:
			massText += "0";
			speedText += "speed of light";
			infoText = "Photons don't interact with the higgsField so they are very fast.";
			break;
		case 1:
			massText += "0.511 MeV/c^2";
			speedText += "There is a certain speed.";
			infoText = "Electrons interact with the field a little so they are fast.";
			break;
		case 2:
			massText += "125.11 GeV/c^2";
			speedText += "Moves slower.";
			infoText = "Higgs bosons interact strongly so they are slow.";
			break;
			
		}

		DrawTextEx(boldPoppins, massText.c_str(), Vector2(114, 68), 48, 5, WHITE);
		DrawTextEx(boldPoppins, speedText.c_str(), Vector2(114, 140), 48, 5, WHITE);
		DrawTextEx(boldPoppins, infoText.c_str(), Vector2(114, 247), 40, 5, WHITE);
		DrawTextEx(Poppins, "Press Space to return home", Vector2(114, 460), 40, 5, GRAY);

		ClearBackground(RAYWHITE);

		EndDrawing();
		if (IsKeyPressed(KEY_SPACE))
		{
			spaceShip();
			break;
		}
	}
	UnloadTexture(background);
	UnloadFont(Poppins);
}