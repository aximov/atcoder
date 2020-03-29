#include <bits/stdc++.h>
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define DEC(i, a, b) for (int i = (a); i > (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
typedef long long ll;
const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;
const ll LINF = (int) 1e18;
const double EPS = 1e-9;

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int ans = 0;
  int ans_ = 0;
  vector<int> v;
  REP(i, n) {
    int a_;
    cin >> a_;
    for (auto e: v) {
      if (e > a_) ++ans_;
    }
    v.pb(a_);
  }
  ans += (ans_ * k) % MOD;

  int rec = 0;
  for (auto e: v) {
    for (auto f: v) {
      if (f > e) ++rec;
    }
  }

  ans += rec * ((k - 1) * (k) / 2 % MOD) % MOD;

  ans %= MOD;
  cout << ans << endl;

  return 0;
}