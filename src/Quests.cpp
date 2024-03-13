#pragma once

#include <string>
#include <set>
#include <unordered_map>

// пока без квестов
struct Quests {
  Quests() = default;

  std::set<uint32_t> current_quests; // тут id наших квестов

  std::set<uint32_t> completed_quests; // тут id выполненных квестов

  std::set<uint32_t> failed_quests; // тут id проваленных квестов

  std::unordered_map<uint32_t, std::string> all_quests; // словарь id -> квест

  // мб словарик id -> текст квеста или что-то в этом роде
};
