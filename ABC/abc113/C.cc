#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  map<int, map<int, int> > mp;  // P => (Yr, i)
  for (int i = 0; i < M; ++i) {
    int P, Y;
    cin >> P >> Y;
    mp[P][Y] = i;
  }

  map<int, string> res;
  for (const auto& e : mp) {
    string p = to_string(e.first);
    while (6 - p.length()) {
      p = '0' + p;
    }

    int cnt = 1;
    for (const auto& city : e.second) {
      int i = city.second;
      string order = to_string(cnt);
      while (6 - order.length()) {
        order = '0' + order;
      }

      res[i] = p + order;
      ++cnt;
    }
  }

  for (const auto& e : res) {
    cout << e.second << endl;
  }
  return 0;
}