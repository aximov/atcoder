#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;

  vector<pair<pair<string, int>, int>> p(N);

  string S;
  int P;
  for (int i = 0; i < N; ++i) {
    cin >> S >> P;
    p[i] = make_pair(make_pair(S, -P), i);
  }

  sort(p.begin(), p.end());
  for (auto e: p) cout << e.second + 1 << endl;

  return 0;
}