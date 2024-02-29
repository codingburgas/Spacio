#pragma once
#include "pch.h"

struct PickPlanet {
	Texture2D sun;
	Texture2D mercury;
	Texture2D venus;
	Texture2D earth;
	Texture2D mars;
	Texture2D jupiter;
	Texture2D saturn;
	Texture2D uranus;
	Texture2D neptune;

	bool objectClicked[9] = { false };
	bool madeChoice = false;

	Music whichCelestialObject;
};

static PickPlanet pickPlanetData;

void pickPlanet(GameState& state);