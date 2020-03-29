#include <bits/stdc++.h>
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
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

  vector<pair<int,int>> V;
  int a,b;
  REP(i,N) {
    cin >> a >> b;
    V.pb({b,a});
  }

  sort(ALL(V));
  int time = 0;
  for(auto e: V) {
    time += e.second;
    if (time > e.first) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}