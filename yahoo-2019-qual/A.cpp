#include <iostream>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  if (N >= K + K - 1) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}