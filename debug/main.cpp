#include <bits/stdc++.h>
//#define int long long
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
//  cin.tie(nullptr);
//  ios::sync_with_stdio(false);

  int n;
  scanf("%d",&n);
  int a[n+1][n];
  FOR(i,1, n+1) {
    FOR(j,1, n) {
      scanf("%d",&a[i][j]);
    }
  }
  int pos[1010] = {1};
  int game = 0;
  int ans = 0;
  set<int> tired;
  bool lock;
  while (game < n * (n - 1) / 2) {
    tired.clear();
    lock = true;
    FOR(i,1, n) {
      if (pos[i] == n) continue;
      int rival = a[i][pos[i]];
      if (pos[rival] == n) {
        cout << -1 << endl;
        return 0;
      }
      if (tired.count(i) == 0 && tired.count(rival) == 0 && a[rival][pos[rival]] == i) {
        lock = false;
        ++game;
        tired.insert(i);
        tired.insert(rival);
        ++pos[i];
        ++pos[rival];
      }
    }
    if (lock) {
      cout << -1 << endl;
      return 0;
    }
    ++ans;
  }

  cout << ans << endl;
  return 0;
}