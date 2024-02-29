#pragma once

#include "GameState.h"
#include "pch.h"

extern int pick;

struct Questions {
	Rectangle planetButton;
	Rectangle higgsButton;
	
	bool buttonClickedPlanets = false;
	bool buttonClickedHiggs = false;

	std::string questions[8] = {
		"Do you choose to gaze at the stars\nor delve into the study\nof micro-particles?",
		"Do you prefer exploring galaxies\nor focusing on elementary particles?",
		"Does your excitement come from\ncosmic phenomena or\natomic structures?",
		"Would you rather investigate black\nholes or examine subatomic\ninteractions?",
		"Do you ponder more on processes in\nstellar cores or on experimental\nresults in particles?",
		"Are you into studying gravitational\nwaves or interactions between\nquarks?",
		"Would you enjoy astronomical\nobservation or analyzing data\nfrom particle experiments ?",
		"Do you prefer examining the vast\nstructures of the Universe or delving\ninto the basics of composite particles?"
	};
	std::string planetsAnswers[8] = { "Stars", "Galaxies", "Cosmic phenomena", "Black holes",
		"Stellar cores", "Gravitational waves", "Astronomical observation", "Vast structures" };
	std::string higgsAnswers[8] = { "Micro-particles", "Elementary particles", "Atomic structures", "Subatomic interactions",
		"Experimental results", "Interactions between quarks", "Analysis of particle data", "Composite particles" };

	int questionCounter;
	int planets;
	int higgs;
};

static Questions questionData;

void questions(GameState& state);

void mouseCursorQuestions(Rectangle planetButton, Rectangle higgsButton);
void confirmReady(int higgs, int planets, int& pick);