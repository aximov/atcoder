#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int m[400][400];

// -1: 未探索
// 0: なし
// 1: あり
map<array<array<int, 2>, 2>, int> result;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int path(array<int, 2> c1, array<int, 2> c2, int W, int H) {
  array<array<int, 2>, 2> in{c1, c2};
  if (c1 == c2) return result[in] = 1;

  auto itr = result.find(in);
  if (itr != result.end()) {
    // すでに調べてある
    return itr->second;
  } else {
    // 未探索

    // c1の上下左右を調べる
    int x = c1[0], y = c1[1];
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      // 範囲チェック
      if (0 <= nx && nx < W && 0 <= ny && ny < H) {
        // 白黒反転
        if (m[nx][ny] == -m[x][y]) {
          array<int, 2> nc1{nx, ny};
          if (path(nc1, c2, W, H) == 1) {
            return result[in] = 1;
          }
        }
      }
    }
  }
  return result[in] = 0;
}

int main() {
  int H, W;
  cin >> H >> W;
  // 黒 # 1
  // 白 . -1
  // 探索中 0
  vector<array<int, 2>> kuro;
  vector<array<int, 2>> shiro;

  for (int i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < W; ++j) {
      array<int, 2> a{i, j};
      if (s[j] == '.') {
        m[i][j] = -1;
        shiro.push_back(a);
      } else if (s[j] == '#') {
        m[i][j] = 1;
        kuro.push_back(a);
      }
    }
  }

  int cnt = 0;
  for (auto& k : kuro) {
    for (auto& s : shiro) {
      if (path(k, s, W, H) == 1) ++cnt;
    }
  }

  cout << cnt << endl;
  return 0;
}