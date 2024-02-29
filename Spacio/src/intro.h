#pragma once

#include "pch.h"
#include "GameState.h"


struct IntroData
{
    Texture2D background;
    Rectangle digIn;
    Rectangle quit;
    bool quitButton;

};

static IntroData introData;

void InitIntroWindow();

void intro(GameState& state);

enum class buttonTypes{
	QUIT,
	DIGIN
};