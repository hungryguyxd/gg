#pragma once

#include <iostream>
#include <string>

#include "MainCharacter.cpp"
#include "Locations.cpp"
#include "Quests.cpp"

class World {
 public:
  // надо ли? :
//  World() {
//    /// Должна запускаться в начале игры, подгружает всё из файликов мб, или просто заполняет переменные
//  }

  World() = default;

  /// Информационные команды:

  void infoHelp() {
    /// Вывод основной инфы о командах
    std::cout << '\n' << "--Информация о командах:" << '\n';
    std::cout << "info_char - Информация о персонаже"  << '\n';
    std::cout << "info_world - Информация о миру" << '\n';
    std::cout << "info_locations - Информация о локациях"<< '\n';
    std::cout << "info_quests - Информация о квестах" << '\n';
    std::cout << "go_to - Начать переход в другую локацию" << '\n';
    std::cout << "next_day - Пропустить день" << '\n';
    std::cout << "---------------" << '\n';
    std::cout << "exit - Выход из игры" << '\n';
    std::cout << "---------------" << '\n';

  }

  void infoCharacter() {
    /// Вывод основной инфы о персонаже: Уровень, Здоровье, Сила атаки(+ сила оружия), Энергия(из максимальной)
    /// + должна предложить вывести всю инфу (см. класс MainCharacter)
    std::cout << '\n' << "Информация о персонаже:" << '\n';
    std::cout << "Уровень: " << player_.GetLevel() << '\n';
    std::cout << "Здоровье: " << player_.GetHealth() << '\n';
    std::cout << "Энергия: " << player_.GetEnergy() << "(" << player_.GetMaxEnergy() << ")" << '\n';
    /// std::cout << "Сила атаки: " << player_.GetBasicAttack() << "(+ " << player_.GetWeaponAttack() << ")" << '\n'; // re do
    std::cout << "Деньги: " << player_.GetMoney() << '\n';
    std::cout << "---------------" << '\n';
    std::cout << "Для остальной информации о персонаже напишите info_char_add" << '\n';
    std::cout << "Для полной информации о персонаже напишите info_char_all" << '\n';
  };

  void infoAddCharacter() {
    /// Вывод дополнительной инфы о персонаже (в будущем)
  };

  void infoAllCharacter() {
    /// Вывод всей инфы о персонаже (в будущем)
  };

  void infoWorld() {
    /// Вывод инфы о мире: День, Локация персонажа, Кол-во взятых квестов
    std::cout << '\n' << "Сегодняший день: " << day_ << '\n';
    std::cout << "Количество взятых квестов: " << quests_.current_quests.size() << '\n';
    std::cout << "#" << '\n';
    std::cout << "Локация: " << locations_.current << '\n';

    /// (в будущем): Кол-во квестов, которые истекают сегодня
  }

  void infoQuests() {
    /// Вывод инфы о квестах: Кол-во взятых квестов, затем их перечисление
    std::cout << '\n' << "Ваши квесты: " << '\n';
    std::cout << "Количество взятых квестов: " << quests_.current_quests.size() << '\n';
    std::cout << "-------------------------" << '\n';
    for (const auto& quest_id : quests_.current_quests) {
      std::cout << "Квест:" << '\n';
      std::cout << quests_.all_quests[quest_id] << '\n';
      std::cout << "-------------------------" << '\n';
    }
  }

  void infoLocations() {
    /// Вывод инфы о локациях: Локация персонажа, затем все доступные локации
    std::cout << '\n' << "Ваша локация: " << locations_.current << '\n';
    std::cout << "-------------------------" << '\n';
    std::cout << "Все локации: " << '\n';
    for (const auto& location : locations_.all_locations) {
      std::cout << location;
      if (location == locations_.current) {
        std::cout << " - вы находитесь здесь";
      }
      std::cout << '\n';
    }
  }

  /// Команды действия:

  void goTo() {
    std::cout << '\n' << "Какую локацию вы хотите посетить?" << '\n';
    std::string location_name;
    std::cin >> location_name;
    /// Ищем локацию, идём туда, тратим энергию (пусть будет 10, потом можно разные значения выставить
    if (locations_.all_locations.contains(location_name)) {
      if (player_.DecreaseEnergy(10)) {
        locations_.current = location_name;
      }
    } else {
      std::cout << "Локация " << location_name << " не существует" << '\n';
    }
    std::cout << "Сейчас вы в: " << locations_.current << '\n';
    locations_.StartEvent(player_);
  }

  void nextDay() {
    /// Скипаем день, восстанавливаем энергию, проверяем квесты
    day_ += 1;
    player_.RestoreEnergy();
    std::cout << "Вы поспали и восстановили энергию" << '\n';
    std::cout << "Сейчас она составляет: " << player_.GetEnergy() << '\n';
    std::cout << "Сегодня " << day_ << " день" << '\n';

    /// тут еще должна быть проверка на зафейленные квесты
  }

 private:
  /// Переменные:
  // <type> quests_, <type> current_location, <type> all_locations, <type> day_, MainCharacter player_,

  MainCharacter player_;

  int32_t day_ = 1;
  Locations locations_;
  Quests quests_;
};

