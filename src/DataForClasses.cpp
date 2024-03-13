#pragma once

#include <iostream>
#include <random>

#include "Random.cpp"

namespace DamageParametrsMc {
const int32_t fist_damage = 2;
const int32_t leg_damage = 3;
const int32_t knife_damage = 8;
const int32_t sword_damage = 11;
const int32_t great_slash_damage = 15;
const int32_t improvised_damage = Random::getRandom(2, 7);
};  // namespace DamageParametrsMc

namespace DamageParametrsDemonCultist {
const int32_t knife_damage = 8;
};  // namespace DamageParametrsDemonCultist

namespace DamageParametrsPlagueKnight {
const int32_t sword_damage = 11;
};  // namespace DamageParametrsDemonCultist