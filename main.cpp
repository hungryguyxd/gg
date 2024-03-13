#include <iostream>
#include <clocale>
#include <string>

#include "src/World.cpp"
#include "src/Control.cpp"

// потом убрать:
#include <set>

int main() {
  setlocale(LC_ALL, "Russian");
  World world;
  Controller control(world);

  std::cout << '\n' << "----Начало-игры---" << '\n';
  std::cout << '\n' << "Приветствуем Вас в нашей игре, введите команду help для помощи" << '\n' << '\n';
  std::string command;
  while (true) {
    std::cin >> command;
    if (command == "exit") {
      break;
    }
    control.acceptCommand(command);
  }
}