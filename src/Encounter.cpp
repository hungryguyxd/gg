#pragma once
#include <iostream>
#include <vector>

#include "MainCharacter.cpp"

template <typename T>
class Fight {
 public:
  explicit Fight(MainCharacter& player) : player_(player) {
    T enemy;
    for (size_t i = 0; i < 3; ++i) {
      enemies_.push_back(enemy);
    }
  }

  void start() {
    std::cout << "Вы встретили врага, между вами завязался бой" << '\n';
    for (T& enemy : enemies_) {
      std::string ans;
      player_.attack(enemy);
      player_.GetHealth() -= enemy.dealDamage();
      std::cout << "Ваше здоровье: " << player_.GetHealth() << '\n'
                << "Здоровье врага: " << enemy.getHealth() << '\n' << '\n';
      std::cout << "Вы хотите сбежать? (да/нет)" << '\n';
      std::cin >> ans;
      if (ans == "да") {
        ////
        std::cout << "ningirundae" << '\n';
      }
    }
    std::cout << "Мы победили, милорд! " << '\n' << '\n';

    // затем изменить награду
    player_.GetMoney() += 100;
    std::cout << "На ваш счёт в Горном банке перечислено 100 золотых" << '\n' << '\n';
  }

 private:
  MainCharacter player_;
  std::vector<T> enemies_;
};