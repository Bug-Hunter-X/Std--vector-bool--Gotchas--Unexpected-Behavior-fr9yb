#include <iostream>
#include <vector>
#include <bitset>

int main() {
  // Problematic use of std::vector<bool>
  std::vector<bool> boolVector(10);
  boolVector[0] = true;

  // Correct alternative: std::vector<char>
  std::vector<char> charVector(10);
  charVector[0] = 1;

  std::cout << "boolVector[0]: " << boolVector[0] << std::endl;
  std::cout << "charVector[0]: " << charVector[0] << std::endl;

  //Better alternative using bitset
  std::bitset<10> bitsetVector;
  bitsetVector[0] = 1;

  std::cout << "bitsetVector[0]: " << bitsetVector[0] << std::endl;

  return 0;
}
