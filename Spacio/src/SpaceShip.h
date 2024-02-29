#pragma once
#include "pch.h"

struct SpaceShip {
	Rectangle character;
	float characterSpeed;

	Rectangle natureLocation;
	Rectangle bosonLocation;
	Rectangle planetsLocation;
	Rectangle spaceship;

	Music audio;

	Texture2D player;
};

static SpaceShip spaceShipData;

void spaceShip(GameState& state);

