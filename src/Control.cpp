#include <iostream>
#include <string>

#include "World.cpp"

struct Controller {
  explicit Controller(World& our_world) : world(our_world) {};
  void acceptCommand(const std::string& command) {
    if (command == "help") {
      world.infoHelp();
    } else if (command == "info_char") {
      world.infoCharacter();
    } else if (command == "info_char_all") {
      world.infoAllCharacter();
    } else if (command == "info_char_add") {
      world.infoAddCharacter();
    } else if (command == "info_locations") {
      world.infoLocations();
    } else if (command == "info_quests") {
      world.infoQuests();
    } else if (command == "info_world") {
      world.infoWorld();
    } else if (command == "go_to") {
      world.goTo();
    } else if (command == "next_day") {
      world.nextDay();
    } else {
      std::cout << '\n' << "Команда не найдена, попробуйте еще раз" << '\n';
    }
  }

  World world;
};