#pragma once
#include "GameState.h"
#include "pch.h"

struct BasicData {
    Texture2D background;
    Texture2D boyCompanion;
    Texture2D girlCompanion;

    Font Poppins;
    Font boldPoppins;

    Music girlVoiceAudio;
    Music boyVoiceAudio;

    float voiceTime;
};

static BasicData basicData;