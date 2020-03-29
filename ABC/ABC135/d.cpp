#include <bits/stdc++.h>
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
typedef long long ll;
const long long MOD = 1000000007LL;
const double EPS = 1e-9;

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  vector<int> dp(13);
  dp[0] = 1;

  for (auto c: S) {
    vector<int> dp_nxt(13);
    REP(i, 10) if (c == '?' || c == (char)('0' + i)) {
        REP(d, 13) (dp_nxt[(d * 10 + i) % 13] += dp[d]) %= MOD;
      }
    dp = dp_nxt;
  }

  cout << dp[5] << endl;
  return 0;
}
