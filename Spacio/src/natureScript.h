#pragma once

#include "pch.h"

struct NatureScript {
    std::string script[8] = {
        "It seems like you have chosen\nto learn about the Universe. So\nwhat exactly is the Universe\nyou may ask. We can\nsimply say that it is everything.",
        "The Universe includes all of\nspace, and all the matter and\nenergy that space contains.\nIt even includes time itself\nand, of course, it includes you.",
        "13.8 billion years ago, a brief\ncosmic inflation period\nrapidly expanded the universe,\ninfluencing its observable\nproperties.",
        "The subsequent Big Bang created\na hot particle soup, leading\nto nucleosynthesis and the\nformation of basic elements.",
        "Recombination, 380,000 years\npost-Big Bang, made the universe\ntransparent, producing the\ncosmic microwave background\nradiation.",
        "After recombination, a dark age\nensued, followed by the\nformation of the first stars in\ncooler regions.",
        "Their light initiated\nreionization, breaking down\nhydrogen atoms and rendering\nthe universe transparent.",
        "Currently, dark energy accelerates\nthe universe's expansion,\nchallenging earlier beliefs and\nprompting ongoing research for\nnew insights into its perpetual\ngrowth."
    };

	std::string boyAstronaut[8] = { "../assets/images/boyBook.png", "../assets/images/boyPointing.png", "../assets/images/boyAstronautSure.png", "../assets/images/boyBook.png", "../assets/images/boyPointing.png", "../assets/images/boyAstronautSure.png", "../assets/images/boyBook.png", "../assets/images/boyPointing.png" };
	std::string girlAstronaut[8] = { "../assets/images/girlBook.png", "../assets/images/girlWorld.png", "../assets/images/girlPointing.png", "../assets/images/girlBook.png", "../assets/images/girlWorld.png", "../assets/images/girlPointing.png", "../assets/images/girlBook.png", "../assets/images/girlWorld.png" };
    
    Texture2D boyImages[8];
	Texture2D girlImages[8];
};

static NatureScript natureScriptData;

void natureScript(GameState& state);