#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> primes {1,2,3,5,7,11,13,17,19,23,29};

  int N, M;
  cin >> N >> M;

  vector<vector<int>> s;
  for (int i = 0; i < M; ++i) {
    int k;
    cin >> k;

    vector<int> v;
    for (int j = 0; j < k; ++j) {
      int s_tmp;
      cin >> s_tmp;

      v.push_back(s_tmp);
    }
    s.emplace_back(v);
  }

  vector<int> p;
  for (int i = 1; i <= M; ++i) {
    int p_tmp;
    cin >> p_tmp;
    p.push_back(p_tmp);
  }

  int ans = 0;
  for (int i = 0; i <= N; ++i) {

    long long pattern = 1;
    for (int j = 0; j < 10; ++j) {
      int b = 1<<j;
      if (i & b) {
        pattern *= primes[j];
      }
    }

    bool flg = true;
    for (int m = 0; m < M; ++m) {
      int cnt = 0;
      for (auto sw: s[m]) {
        if (pattern % primes[sw] == 0) ++cnt;
      }
      if (cnt % 2 != p[m]) flg = false;
    }
    if(flg) ++ans;

  }

  cout << ans << endl;

  return 0;
}