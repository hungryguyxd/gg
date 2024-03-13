#pragma once

#include <iostream>
#include <random>

struct Random {
  static int32_t getRandom(int32_t lhs, int32_t rhs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lhs, rhs);
    return distr(gen);
  }
};