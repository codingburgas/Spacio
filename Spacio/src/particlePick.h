#pragma once
#include "pch.h"

extern bool hasMass;

struct ParticlePick
{
	Rectangle masslessParticle;
	Rectangle massParticle;
};

static ParticlePick particlePickData;

void particlePick(GameState& state);