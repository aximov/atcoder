#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A;
  int a;
  long long asum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);
    asum += a;
  }

  vector<int> B;
  int b;
  long long bsum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> b;
    B.push_back(b);
    bsum += b;
  }

  int change_i = -1;

  if (asum >= bsum) {
    // 準備度合計が十分にある
    change_i = 0;

    // 余裕度チェック
    vector<int> yoyu;
    vector<int> fusoku;
    for (int i = 0; i < N; ++i) {
      int d = A[i] - B[i];
      if (d > 0) {
        yoyu.push_back(d);
      } else if (d < 0) {
        // 正であることに注意
        fusoku.push_back(-d);
      }
    }

    // 後ろのほうが大きい
    sort(yoyu.begin(), yoyu.end());
    sort(fusoku.begin(), fusoku.end());

    int y = 0;
    while (!fusoku.empty()) {
      int f = fusoku.back();
      fusoku.pop_back();
      ++change_i;

      while (f > 0) {
        // 大きい余裕から取り出す
        if (y == 0) {
          y = yoyu.back();
          ++change_i;
        }

        if (f >= y) {
          yoyu.pop_back();
          f -= y;
          y = 0;
        } else if (f < y) {
          y -= f;
          f = 0;
        }
      }
    }
  }

  cout << change_i << endl;
  return 0;
}