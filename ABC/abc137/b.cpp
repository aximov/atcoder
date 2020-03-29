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
  int K,X;
  cin>>K>>X;
  FOR(i,X-K+1,X+K) {
    if (i < -1000000 || i > 1000000) continue;
    cout << i;
    if(i == X+K) break;
    cout << " ";
  }
  cout << endl;
  return 0;
}