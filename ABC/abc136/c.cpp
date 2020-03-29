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
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> H;
  int h;
  REP(i,N) {
    cin >> h;
    H.pb(h);
  }
  for(int i = N - 1; i > 0; --i) {
    if (H[i-1] <= H[i]) continue;
    if (H[i-1] == H[i] + 1) {
      --(H[i-1]);
      continue;
    }
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}