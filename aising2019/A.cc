#include <iostream>

using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  int res = (N - W + 1) * (N - H + 1);
  if (res < 0)
    cout << 0 << endl;
  else
    cout << res << endl;
  return 0;
}