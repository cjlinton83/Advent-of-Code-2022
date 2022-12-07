#include "./include/d6.h"
#include "./include/util.h"

int main() {
  std::vector<std::string> input;
  get_input(input, "./data/d6.txt");

  d6::run(input);
  return 0;
}