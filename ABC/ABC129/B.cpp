#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> W;
  int w;
  for(int i = 0; i < N; ++i) {
    cin >> w;
    W.push_back(w);
  }

  int ans = 10000;

  for(int i = 1; i < N; ++i) {
    int s_1 = 0, s_2 = 0;

    for(int j = 0; j <= i; ++j) {
      s_1 += W[j];
    }
    for(int j = i + 1; j < N; ++j) {
      s_2 += W[j];
    }

    ans = min(ans, abs(s_1 - s_2));
  }

  cout << ans << endl;
  return 0;
}