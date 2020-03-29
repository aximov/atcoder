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
  map<int,int> A;

  int a;
  REP(i, N) {
    cin >> a;
    if(A.find(a) == A.end()) {
      A.insert({a,1});
    } else {
      A.find(a)->second++;
    }
  }

  vector<int> l;
  for(auto itr = rbegin(A); itr != rend(A); ++itr) {
    while (itr->second >= 2 && l.size() < 2) {
      l.pb(itr->first);
      itr->second -= 2;
    }
    if (l.size() == 2) {
      cout << l[0] * l[1] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}