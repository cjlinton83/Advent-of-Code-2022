#include <iostream>
#include <set>

#include "../include/d6.h"

int do_work(const std::string &line, const int n);

void d6::run(const std::vector<std::string> &data) {
  for (auto line : data) {
    part_1(line, 4);
    part_2(line, 14);
  }
}

void d6::part_1(const std::string &line, const int n) {
  int result = do_work(line, n);
  std::cout << "Part1: " << result << std::endl;
}

void d6::part_2(const std::string &line, const int n) {
  int result = do_work(line, n);
  std::cout << "Part2: " << result << std::endl;
}

/* Find the substring that has all unique characters length n */
int do_work(const std::string &line, const int n) {
  int start = 0;
  int end = start + n;

  // While substring with n unique characters isn't found continue until finding
  // one. Assume that each line of input is solvable.
  while (true) {
    // Use set to collect unique characters in substring length n
    std::set<char> workspace;
    auto s = line.substr(start, n);
    for (char c : s)
      workspace.insert(c);

    // If set contains n unique characters then we are done.
    if (workspace.size() == n)
      break;

    // If set doesn't contain n unique characters increment our positions.
    start += 1;
    end += 1;
  }

  // end is the position just after the last character in the substring.
  return end;
}