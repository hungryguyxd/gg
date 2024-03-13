#pragma once

#include <iostream>
#include "DataForClasses.cpp"

class CommonEnemy {
 public:
  CommonEnemy() = default;
  static void getDamage(int32_t damage) { health_ -= damage; }

  int32_t getHealth() { return health_; }

 protected:
  static int32_t health_;
};

class DemonCultist : public CommonEnemy {
 public:
  DemonCultist() : health_(20) {}

  int32_t dealDamage() {
    return DamageParametrsDemonCultist::knife_damage;
  }

 private:
  int32_t health_;
};

class PlagueKnight : public CommonEnemy {
 public:
  PlagueKnight() : health_(50) {}

  int32_t dealDamage() {
    return DamageParametrsPlagueKnight::sword_damage;
  }

 private:
  int32_t health_;
};