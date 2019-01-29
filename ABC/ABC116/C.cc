#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> h;
  int htmp;
  int maxh;
  for (int i = 0; i < N; ++i) {
    cin >> htmp;
    maxh = max(maxh, htmp);
    h.push_back(htmp);
  }

  int cnt = 0;
  int h_now = 0;
  int number_of_section = 0;

  while (h_now < maxh) {
    ++h_now;

    bool flg_insection = false;
    for (int i = 0; i < N; ++i) {
      if (h[i] >= h_now) {
        if (!flg_insection) {
          ++cnt;
          flg_insection = true;
        }
      } else {
        flg_insection = false;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}