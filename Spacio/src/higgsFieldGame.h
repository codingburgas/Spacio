#pragma once
#include "pch.h"

struct HiggsBoson {
	Texture2D particle;
	int horizontalStep;
	int particleVertical;
	int particleHorizontal;

	Music girlPhoton;
	Music boyPhoton;
	Music girlElectron;
	Music boyElectron;
	Music girlHiggs;
	Music boyHiggs;

	float electronAudioTime;
	float higgsAudioTime;
};

static HiggsBoson higgsBoson;

void HiggsFieldGame(GameState& state);