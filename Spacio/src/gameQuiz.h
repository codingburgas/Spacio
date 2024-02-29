#pragma once

#include "pch.h"

struct GameQuiz {
	Vector2 position;
	Vector2 velocity;

	bool answerTopClicked = false;
	bool answerMiddleClicked = false;
	bool answerBottomClicked = false;

	int wrongCounter;

	Texture2D blackHole;
	Texture2D spaceShip;

	std::string questions[8] = { "What is dark matter?",
	"How do black holes form?", "What role do magnetic\nfields play in shaping\ncelestial bodies in space?",
	"How do astronomers detect\nand study exoplanets?", "What is cosmic microwave\nbackground radiation?",
	"How do gravitational\nwaves offer new insights\ninto astronomical phenomena?",
	"What is dark energy?", "How do phenomena like\nsupernovas impact the\ncomposition of galaxies\nand the formation of elements?"
	};

	std::string rightAnswers[8] = { "Invisible, mysterious mass.", "Star collapse, supernova.",
	"Guidance, alignment, protection.", "Observation, instruments, analysis.", "Ancient light echo.",
	"Space-time ripples, observations.", "Unknown cosmic force.", "Heavy element production."
	};

	std::string wrongAnswersBottom[8] = {"Cosmic invisible shadows.", "Galactic phantom substance.",
	"Cosmic doughnuts emerge.", "Stellar confetti formation.", "Celestial body puppetry.", "Galactic hairdressers' influence.",
	"Psychic star-gazing.", "Tea leag reading."};

	std::string wrongAnswersMiddle[8] = {
		"Galactic disco glow.", "Microwave oven residue.", "Alien dance signals.",
		"Celestial taco waves.", "Galactic happiness field.", "Cosmic rainbow essence.",
		"Celestial spice mixing.", "Galactic confetti party."
	};

	int num;
	int questionCounter;

	bool moveOnce = true;
	Vector2 targetPosition;

	Rectangle answerTop;
	Rectangle answerMiddle;
	Rectangle answerBottom;

	Color Purple;
};

static GameQuiz gameQuizData;

void gameQuiz(GameState& state);