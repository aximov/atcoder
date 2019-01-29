#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main() {
  int N, M;
  long long K;
  string s;
  cin >> N >> M >> K >> s;
  s = " " + s;  // 1-based
  map<int, set<int>> mp;
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    mp[a].insert(b);
    mp[b].insert(a);
  }
  K &= 1;
  if (K) {
    for (int i = 1; i <= N; ++i) {
      // スタートの隣に青が存在するか
      bool flg = false;
      for (auto e : mp[i]) {
        if (s[e] == 'B') flg = true;
      }
      if (flg)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    }
  } else {
    // 準備: 各頂点について、隣が1つでもRか
    vector<bool> has_R;
    has_R.push_back(false);  // 1-based
    for (int i = 1; i <= N; ++i) {
      bool flg = false;
      for (auto n : mp[i]) {
        if (s[n] == 'R') flg = true;
      }
      has_R.push_back(flg);
    }

    for (int i = 1; i <= N; ++i) {
      // スタートに隣接する頂点のうち、隣に青しかないものが存在するか
      bool flg = false;
      for (auto n : mp[i]) {
        if (!has_R[n]) flg = true;
      }
      if (flg)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    }
  }

  return 0;
}