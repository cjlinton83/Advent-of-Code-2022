#include <iostream>

#include "../include/d3.h"

void d3::part_1(const std::vector<std::string> &data) {
  int score = 0;

  for (std::string line : data) {
    // split line of input into equal substrings
    std::string left = line.substr(0, line.size() / 2);
    std::string right = line.substr(line.size() / 2, line.size() - 1);

    // find same character in both substrings
    char same = 0;
    for (char c : left) {
      if (right.find(c) != std::string::npos) {
        same = c;
        break;
      }
    }

    // score character that is same in both substrings
    if (same >= 'a' && same <= 'z')
      score += same - 'a' + 1;
    if (same >= 'A' && same <= 'Z')
      score += same - 'A' + 27;
  }

  std::cout << "Part 1: " << score << std::endl;
}

void d3::part_2(const std::vector<std::string> &data) {
  int score = 0;

  for (size_t i = 0; i < data.size(); i += 3) {
    // select lines in groups of three
    std::string line_one = data[i];
    std::string line_two = data[i + 1];
    std::string line_three = data[i + 2];

    // find same character in group
    char same = 0;
    for (char c : line_one) {
      if (line_two.find(c) != std::string::npos &&
          line_three.find(c) != std::string::npos) {
        same = c;
        break;
      }
    }

    // score character that is same in group
    if (same >= 'a' && same <= 'z')
      score += same - 'a' + 1;
    if (same >= 'A' && same <= 'Z')
      score += same - 'A' + 27;
  }

  std::cout << "Part 2: " << score << std::endl;
}
