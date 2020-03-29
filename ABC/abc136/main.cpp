#include <vector>
#include <string>
#include <iostream>
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
  string S;
  cin >> S;
  int N = S.length();
  vector<int> s(N);
  REP(i,N) {
    if(S[i] == 'R') s[i] = 1;
    else s[i] = -1;
  }
  vector<int> v(N, 0);

  REP(i,N) {
    int pos = i;
    int pre_value = s[i];
    int value = 0;
    int oe_flg = 0;
    while(value * pre_value != -1) {
      pos += pre_value;
      value = s[pos];
      ++oe_flg;
    }
    if (oe_flg % 2 == 0) ++v[pos];
    else ++v[pos - pre_value];
  }
  for(auto e: v) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}