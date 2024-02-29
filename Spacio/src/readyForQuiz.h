#pragma once
#include "pch.h"

struct ReadyForQuiz {
	Texture2D starYes;
	Texture2D starNo;

	Rectangle buttonYes;
	Rectangle buttonNo;
};

static ReadyForQuiz readyForQuizData;

void readyForQuiz(GameState& state);