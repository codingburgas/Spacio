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

	if (hasMass) {
		particleVertical -= verticalStep;
		horizontalStep /= 2;
	}

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
			infoText = "info";
			break;
		case 1:
			massText += "0.511 MeV/c^2";
			speedText += "speed";
			infoText = "info";
			break;
		case 2:
			massText += "125.11 GeV/c^2";
			speedText += "speed";
			infoText = "info";
			break;
			
		}

		DrawTextEx(boldPoppins, massText.c_str(), Vector2(114, 68), 48, 5, WHITE);
		DrawTextEx(boldPoppins, speedText.c_str(), Vector2(117, 140), 48, 5, WHITE);
		DrawTextEx(boldPoppins, infoText.c_str(), Vector2(665, 59), 40, 5, WHITE);

		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	UnloadTexture(background);
	UnloadFont(Poppins);
}