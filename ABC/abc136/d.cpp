#include <bits/stdc++.h>
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
typedef long long ll;
const int MOD = (int) 1e9 + 7;
const double EPS = 1e-9;

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  vector<int> RL;
  int init = 0;
  while (true) {
    auto pos = S.find("RL", init);
    if (pos == std::string::npos) break;
    RL.pb((int) pos);
    init = (int) pos + 1;
  }

  int N = S.length();
  vector<int> ans(N, 0);
  REP(i, N) {
    decltype(RL)::iterator itr;
    if (S[i] == 'R') itr = lower_bound(ALL(RL), i);
    else itr = --upper_bound(ALL(RL), i);
    int d = abs(*itr - i);
    if (d % 2 == 0) ++ans[*itr];
    else ++ans[*itr + 1];
  }

  for (auto e: ans) cout << e << " ";
  cout << endl;
  return 0;
}