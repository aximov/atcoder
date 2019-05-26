#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  vector<vector<int>> s(M);
  for (int i = 0; i < M; ++i) {
    int k;
    cin >> k;

    s[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> s[i][j];
      --s[i][j];
    }
  }

  vector<int> p(M);
  for (int i = 0; i < M; ++i) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << N); ++i) {
    bool flg = true;

    for (int m = 0; m < M; ++m) {
      int cnt = 0;
      for (auto sw: s[m]) {
        if ((i >> sw) & 1) ++cnt;
      }
      if (cnt % 2 != p[m]) flg = false;
    }
    if(flg) ++ans;

  }

  cout << ans << endl;

  return 0;
}