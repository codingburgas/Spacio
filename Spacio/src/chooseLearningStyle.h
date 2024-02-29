#pragma once
#include "GameState.h"
#include "pch.h"

struct ChooseLearningStyle
{
	Texture2D background;

	Font Poppins;
	Font boldPoppins;

	Rectangle reading;
	Rectangle playing;
};

static ChooseLearningStyle chooseLearningStyleData;

void chooseLearningStyle(GameState& state);