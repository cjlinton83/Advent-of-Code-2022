#include <algorithm>
#include <functional>
#include <iostream>

#include "../include/d1.h"

std::vector<int> calCount;

void d1::init_data(const std::vector<std::string> &input) {
  int count = 0;
  for (auto line : input) {
    if (line == "" || line == "\n") {
      calCount.push_back(count);
      count = 0;
      continue;
    }

    count += std::stoi(line);
  }
  calCount.push_back(count);

  std::sort(calCount.begin(), calCount.end(), std::greater<int>());
}

void d1::part_1() {
  std::cout << "Part 1: Highest calories for top elf\t\t" << calCount[0]
            << std::endl;
}

void d1::part_2() {
  int count;
  count = calCount[0] + calCount[1] + calCount[2];

  std::cout << "Part 2: Sum of calories for top three elfs\t" << count
            << std::endl;
}
