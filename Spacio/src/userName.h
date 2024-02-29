#pragma once
#include "pch.h"
#include "GameState.h"

extern std::string name;

struct UserNameData {
    Texture2D backgroundUserName;
    Music audioUserName;
    Rectangle inputBox;
    int maxChars;
    std::string station;
    int letterCount;
    bool mouseOnText = false;
    int framesCounter;

    float audioSecondUserName;
};

static UserNameData userNameData;

void InitUserNameWindow();

void userName(GameState& state);