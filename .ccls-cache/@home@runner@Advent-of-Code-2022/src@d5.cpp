#include <iostream>
#include <stack>
#include <vector>

#include "../include/d5.h"

// Test Stacks
// std::vector<std::stack<char>> stacks = {
//     std::stack<char>(std::deque<char>{'Z', 'N'}),
//     std::stack<char>(std::deque<char>{'M', 'C', 'D'}),
//     std::stack<char>(std::deque<char>{'P'}),
// };
// std::vector<int> moves = {1, 2, 1, 3, 1, 3, 2, 2, 1, 1, 1, 2};

// Final Stacks
std::vector<std::stack<char>> stacks = {
    std::stack<char>(std::deque<char>{'Q','M','G','C','L'}),
    std::stack<char>(std::deque<char>{'R','D','L','C','T','F','H','G'}),
    std::stack<char>(std::deque<char>{'V','J','F','N','M','T','W','R'}),
    std::stack<char>(std::deque<char>{'J','F','D','V','Q','P'}),
    std::stack<char>(std::deque<char>{'N','F','M','S','L','B','T'}),
    std::stack<char>(std::deque<char>{'R','N','V','H','C','D','P'}),
    std::stack<char>(std::deque<char>{'H','C','T'}),
    std::stack<char>(std::deque<char>{'G','S','J','V','Z','N','H','P'}),
    std::stack<char>(std::deque<char>{'Z','F','H','G'}),
};
std::vector<int> moves;

void d5::init_data(const std::vector<std::string> &data) {
  // find spaces.
  for (auto line : data) {
    std::vector<int> spaces;
    for (int i = 0; i < line.size(); i++)
      if (line[i] == ' ')
        spaces.push_back(i);

     // parse ints between spaces.
    int nMoves = std::stoi(line.substr(spaces[0]+1, spaces[1]));
    int from = std::stoi(line.substr(spaces[2]+1, spaces[3]));
    int to = std::stoi(line.substr(spaces[4]+1));

    // add ints to moves vector.
    moves.push_back(nMoves);
    moves.push_back(from);
    moves.push_back(to);
  }
}

void d5::part_1() {
  for (int i = 0; i < moves.size(); i+=3) {
    // Store next three moves: n = number of crates to move, from = stack to move from, to = stack to move to.
    int n = moves[i];
    int from = moves[i+1]-1;
    int to = moves[i+2]-1;

    // Stacks are manipulated one item at a time from...to
    for (int j = 0; j < n; j++) {
      char c = stacks[from].top();
      stacks[from].pop();
      stacks[to].push(c);
    }
  }

  // Store top element of each stack into result and display the results
  std::vector<char> result;
  for (int i = 0; i < stacks.size(); i++) {
    result.push_back(stacks[i].top());
  }
  std::cout << std::string(result.begin(), result.end()) << std::endl;
}

void d5::part_2() {
    for (int i = 0; i < moves.size(); i+=3) {
    // Store next three moves: n = number of crates to move, from = stack to move from, to = stack to move to.
    int n = moves[i];
    int from = moves[i+1]-1;
    int to = moves[i+2]-1;

    // Stacks are manipulated one stack at a time from...to (order of crates stays same between stacks)
    std::stack<char> workingStack;
    for (int j = 0; j < n; j++) {
      char c = stacks[from].top();
      stacks[from].pop();
      workingStack.push(c);
    }
    while (!workingStack.empty()) {
      char c = workingStack.top();
      workingStack.pop();
      stacks[to].push(c);
    }
  }
  // Store top element of each stack into result and display the results
  std::vector<char> result;
  for (int i = 0; i < stacks.size(); i++) {
    result.push_back(stacks[i].top());
  }
  std::cout << std::string(result.begin(), result.end()) << std::endl;
}