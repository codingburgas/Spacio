#pragma once
#include "pch.h"
#include "GameState.h"

extern bool girlVoice;
extern bool boyVoice;

struct CharacterPickData {
	Texture2D backgroundCharacter;
	
	Texture2D boyAstronautImg;
	Texture2D girlAstronautImg;

	Rectangle boyBox;
	Rectangle girlBox;

	Music characterPickAudio;
	float audioSecondCharacter;
};

static CharacterPickData characterPickData;

void InitCharacterPick();

void characterPick(GameState& state);