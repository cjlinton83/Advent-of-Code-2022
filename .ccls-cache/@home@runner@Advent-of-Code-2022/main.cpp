#include "./include/d5.h"
#include "./include/util.h"

int main() {
  std::vector<std::string> input;
  get_input(input, "./data/d5t.txt");

  d5::part_1();
  //d5::part_2();

  return 0;
}