#include <fstream>
#include <iostream>

#include "../include/util.h"

void get_input(std::vector<std::string> &input, std::string filename) {
  std::ifstream file(filename);

  while (!file.eof()) {
    std::string s;
    getline(file, s);
    input.push_back(s);
  }
}

void display_input(const std::vector<std::string> &input) {
  for (auto line : input) {
    std::cout << line << std::endl;
  }
}