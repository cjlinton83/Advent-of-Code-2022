#include <algorithm>
#include <iostream>
#include <set>

#include "../include/d4.h"

std::vector<std::set<int>> sets;

void d4::init_data(const std::vector<std::string> &data) {
  for (auto line : data) {
    // first range
    auto range = line.substr(0, line.find(','));
    auto start = range.substr(0, range.find('-'));
    auto end = range.substr(range.find('-') + 1, range.size() - 1);
    std::set<int> first_range;
    for (int n = std::stoi(start); n <= std::stoi(end); n++)
      first_range.insert(n);
    sets.push_back(first_range);

    // second range
    range = line.substr(line.find(',') + 1, line.size() - 1);
    start = range.substr(0, range.find('-'));
    end = range.substr(range.find('-') + 1, range.size() - 1);
    std::set<int> second_range;
    for (int n = std::stoi(start); n <= std::stoi(end); n++)
      second_range.insert(n);
    sets.push_back(second_range);
  }
}

void d4::part_1() {
  int pairs = 0;

  for (auto i = 0; i < sets.size(); i += 2) {
    if (std::includes(sets[i].begin(), sets[i].end(), sets[i + 1].begin(),
                      sets[i + 1].end()) ||
        std::includes(sets[i + 1].begin(), sets[i + 1].end(), sets[i].begin(),
                      sets[i].end())) {
      pairs += 1;
    }
  }

  std::cout << "Part 1: " << pairs << std::endl;
}

void d4::part_2() {
  int overlapping_pairs = 0;

  for (auto i = 0; i < sets.size(); i += 2) {
    std::vector<int> overlapping;
    std::set_intersection(sets[i].begin(), sets[i].end(), sets[i + 1].begin(),
                          sets[i + 1].end(), std::back_inserter(overlapping));
    if (overlapping.size() != 0)
      overlapping_pairs += 1;
  }
  
  std::cout << "Part 2: " << overlapping_pairs << std::endl;
}