#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long L;
  cin >> L;
  vector<long long> need_stone;
  need_stone.emplace_back(0);
  long long tmp;
  for (long long i = 1; i <= L; ++i) {
    cin >> tmp;
    need_stone.emplace_back(tmp);
  }
  return 0;
}