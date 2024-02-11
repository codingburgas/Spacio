#include "getStation.h"



void getStation() {
	Font Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 1000, NULL, 0);
	Font boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 1000, NULL, 0);

	Texture2D background = LoadTexture("../assets/images/getStationBackground.png");

	while (!WindowShouldClose()) {
		

		BeginDrawing();
		

		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, RAYWHITE);
		DrawTextEx(Poppins,"Hey kurva",Vector2(20, 20), 50, 5, BLACK);

		

		EndDrawing();

	}
}
