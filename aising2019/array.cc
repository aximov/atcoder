#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 2> a{1, 2};
  array<array<int, 2>, 1> b{a};
  return 0;
}