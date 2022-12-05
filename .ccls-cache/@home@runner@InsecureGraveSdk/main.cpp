#include "./include/d1.h"
#include "./include/util.h"

int main() {
  std::vector<std::string> input;
  get_input(input, "./data/d1.txt");

  init_data(input);
  part_1();
  part_2();

  return 0;
}