#include "particlePick.h"
#include "higgsFieldGame.h"
#include "basicData.h"
#include <iostream>

void InitParticlePickWindow()
{
    basicData.background = LoadTexture("../assets/images/chooseParticleBg.png");
    basicData.Poppins = LoadFontEx("../assets/fonts/Poppins-Regular.ttf", 100, 0, 0);
    basicData.boldPoppins = LoadFontEx("../assets/fonts/Poppins-Bold.ttf", 100, 0, 0);
    basicData.voiceTime = 0.0;
    basicData.girlVoiceAudio = LoadMusicStream("../assets/audios/chooseParticleFemale.mp3");
    basicData.boyVoiceAudio = LoadMusicStream("../assets/audios/chooseParticleMale.mp3");

    particlePickData.masslessParticle = { 283, 302, 295, 295 };
    particlePickData.massParticle = { 830,304 ,295 ,295 };
}

bool mouseCursorOnRectangle(Rectangle rectangle) {
    if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
        return true;
    }

    return false;
}

void mouseCursorParticles(Rectangle masslessParticle, Rectangle massParticle)
{
    // Set mouse cursor based on collision
    if (CheckCollisionPointRec(GetMousePosition(), masslessParticle)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else if (CheckCollisionPointRec(GetMousePosition(), massParticle)) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    }
    else {
        SetMouseCursor(MOUSE_CURSOR_ARROW);
    }
}
bool hasMass;
bool loadParticle = true;

void particlePick(GameState& state) {

    if (loadParticle)
    {
        InitParticlePickWindow();
        loadParticle = false;
        SetMouseCursor(MOUSE_CURSOR_ARROW);
        PlayMusicStream(basicData.boyVoiceAudio);
        PlayMusicStream(basicData.girlVoiceAudio);
    }

    if (girlVoice)
    {
        PlayMusicStream(basicData.girlVoiceAudio);
        if (IsMusicStreamPlaying(basicData.girlVoiceAudio) and basicData.voiceTime <= 5.0)
        {
            UpdateMusicStream(basicData.girlVoiceAudio);
            basicData.voiceTime += GetFrameTime();
        }
    }
    else if (boyVoice)
    {
        PlayMusicStream(basicData.boyVoiceAudio);
        if (IsMusicStreamPlaying(basicData.boyVoiceAudio) and basicData.voiceTime <= 4.0)
        {
            UpdateMusicStream(basicData.boyVoiceAudio);
            basicData.voiceTime += GetFrameTime();
        }
    }

    DrawTexture(basicData.background, 0, 0, RAYWHITE);
    // Draw text
    DrawTextEx(basicData.boldPoppins, "What do you want to be?", Vector2(336, 118), 64, 5, WHITE);
    DrawTextEx(basicData.boldPoppins, "Massless particle ", Vector2(294, 605), 32, 5, WHITE);
    DrawTextEx(basicData.boldPoppins, "Particle with mass", Vector2(835, 605), 32, 5, WHITE);

    // Check mouse cursor interaction with particles 
    mouseCursorParticles(particlePickData.masslessParticle, particlePickData.massParticle);

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (mouseCursorOnRectangle(particlePickData.masslessParticle)) {
            hasMass = false;
            state = GameState::HiggsBoson;
        }
        else if (mouseCursorOnRectangle(particlePickData.massParticle)) {
            hasMass = true;
            state = GameState::HiggsBoson;
        }
    }
}