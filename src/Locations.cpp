#pragma once

#include <string>
#include <set>
#include "Encounter.cpp"
#include "Enemies.cpp"

struct Locations {
  Locations() = default;

  /// Должен выполняться автоматически при входе на локацию
  void StartEvent(MainCharacter& player) {
    if (current == "Village") {
      /// квесты старосты (как появится)
    } else if (enemies_locations.contains(current)) {
      std::cout << '\n' << "Вы вступаете в бой в локации " << current << '\n' << '\n';

      /// начало боя
      Fight<DemonCultist> fight(player);
      fight.start();
    }
  }

  std::string current = "Village";
  std::set<std::string> all_locations = {"Village", "Swamp", "Ruins"};

  std::set<std::string> enemies_locations = {"Swamp", "Ruins"};
};
