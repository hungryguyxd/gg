#pragma once

#include <iostream>
#include <random>
#include <unordered_map>

#include "DataForClasses.cpp"

struct Weapons {
  Weapons() {
    weapon_[knife] = 0;
    weapon_[longsword] = 0;
    weapon_[improvised] = 0;
    weapon_[fist] = 1;
    weapon_[leg] = 1;
  }

  static std::unordered_map<std::string, size_t>& getWeapon() {
    return weapon_;
  }

  static std::unordered_map<std::string, size_t> weapon_;
  std::string knife, longsword, improvised, fist, leg;
};

struct Armor {
  Armor() = default;

  bool shield{false};
};

class MainCharacter {
 public:
  MainCharacter() = default;

  template <typename T>
  void attack(T& enemy) {
    std::string val;
    textBeforeAttack();
    std::cin >> val;
    if (val == "назад") {
      ////emplement smth later
    }
    defaultAttack(enemy, val);
  }

  int32_t& GetLevel() { return level_; }
  const int32_t& GetLevel() const { return level_; }

  int32_t& GetHealth() { return health_; }
  const int32_t& GetHealth() const { return health_; }

  int32_t& GetEnergy() { return energy_; }
  const int32_t& GetEnergy() const { return energy_; }

  int32_t& GetMaxEnergy() { return max_energy_; }
  const int32_t& GetMaxEnergy() const { return max_energy_; }

  int32_t& GetMoney() { return money_; }
  const int32_t& GetMoney() const { return money_; }

  bool DecreaseEnergy(int32_t expended) {
    bool result = true;
    if (energy_ - expended >= 0) {
      energy_ -= expended;
      std::cout << "Вы затратили " << expended << " энергии" << '\n';
    } else {
      std::cout << "У вас недостаточно энергии" << '\n';
      result = false;
    }
    std::cout << "Сейчас у вас " << energy_ << '\n';
    return result;
  }

  void RestoreEnergy() { energy_ = max_energy_; }

 private:
  void textBeforeAttack() {
    std::cout << "На данный момент у меня в арсенале: ";
    for (const auto& type_attack : Weapons::getWeapon()) {
      if (type_attack.second == 0) {
        std::cout << type_attack.first << ' ';
      }
    }
    std::cout << "что же выбрать?" << '\n';
  }

  template <typename T>
  void defaultAttack(T& enemy, const std::string& weapon) {
    if (weapon == "fist") {
      enemy.getDamage(DamageParametrsMc::fist_damage);
    }
    if (weapon == "leg") {
      enemy.getDamage(DamageParametrsMc::fist_damage);
    }
    if (weapon == "knife") {
      enemy.getDamage(DamageParametrsMc::fist_damage);
    }
    if (weapon == "improvised") {
      enemy.getDamage(DamageParametrsMc::fist_damage);
    }
    if (weapon == "longsword") {
      enemy.getDamage(DamageParametrsMc::fist_damage);
    }
  }

  int32_t health_{50};  // это здоровье)
  int32_t money_{0};
  int32_t armor_{0};
  int32_t mana_{20};
  int32_t harisma_{15};
  int32_t energy_{100};
  int32_t max_energy_{100};
  int32_t strenth{25};
  int32_t agility_{50};
  int32_t mastery_{10};
  int32_t level_{0};
};