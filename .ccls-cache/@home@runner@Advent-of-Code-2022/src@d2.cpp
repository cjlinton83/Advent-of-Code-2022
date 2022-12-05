#include <algorithm>
#include <iostream>

#include "../include/d2.h"

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

const int LOSE = 0;
const int DRAW = 3;
const int WIN = 6;

void d2::part_1(const std::vector<std::string> &data) {
  const std::string WINS[] = {"A Y", "B Z", "C X"};
  const std::string LOSES[] = {"A Z", "B X", "C Y"};
  const std::string DRAWS[] = {"A X", "B Y", "C Z"};

  int score = 0;

  for (auto line : data) {
    if (line == "" || line == "\n")
      continue;

    if (std::find(std::begin(WINS), std::end(WINS), line) != std::end(WINS)) {
      score += WIN;
    }
    if (std::find(std::begin(LOSES), std::end(LOSES), line) !=
        std::end(LOSES)) {
      score += LOSE;
    }
    if (std::find(std::begin(DRAWS), std::end(DRAWS), line) !=
        std::end(DRAWS)) {
      score += DRAW;
    }

    score += line[2] == 'X' ? 1 : 0;
    score += line[2] == 'Y' ? 2 : 0;
    score += line[2] == 'Z' ? 3 : 0;
  }

  std::cout << "Part 1: " << score << std::endl;
}

void d2::part_2(const std::vector<std::string> &data) {
  int score = 0;

  for (auto line : data) {
    if (line == "" || line == "\n")
      continue;

    char move = line[0];
    char outcome = line[2];

    int score_move;
    int score_outcome;

    // ROCK
    if (move == 'A') {
      if (outcome == 'X') {
        score_outcome = LOSE;
        score_move = SCISSORS;
      }
      if (outcome == 'Y') {
        score_outcome = DRAW;
        score_move = ROCK;
      }
      if (outcome == 'Z') {
        score_outcome = WIN;
        score_move = PAPER;
      }
    }
    // PAPER
    if (move == 'B') {
      if (outcome == 'X') {
        score_outcome = LOSE;
        score_move = ROCK;
      }
      if (outcome == 'Y') {
        score_outcome = DRAW;
        score_move = PAPER;
      }
      if (outcome == 'Z') {
        score_outcome = WIN;
        score_move = SCISSORS;
      }
    }
    // SCISSORS
    if (move == 'C') {
      if (outcome == 'X') {
        score_outcome = LOSE;
        score_move = PAPER;
      }
      if (outcome == 'Y') {
        score_outcome = DRAW;
        score_move = SCISSORS;
      }
      if (outcome == 'Z') {
        score_outcome = WIN;
        score_move = ROCK;
      }
    }

    score += score_move + score_outcome;
  }

  std::cout << "Part 2: " << score << std::endl;
}
