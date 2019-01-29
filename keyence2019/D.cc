#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A, B;
  int a, b;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);
  }
  for (int i = 0; i < N; ++i) {
    cin >> b;
    B.push_back(b);
  }

  return 0;
}