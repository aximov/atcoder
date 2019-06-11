#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

int main() {
  int N,M;
  cin >> N >> M;

  vector<bool> oks(N + 1, true);
  int _a;
  for(int i = 0; i < M; ++i) {
    cin >> _a;
    oks[_a] = false;
  }

  vector<long long> dp(N + 1, 0);
  dp[0] = 1;
  for(int now = 0; now < N; ++now) {
    for (int next = now + 1; next <= min(N, now + 2); ++next) {
      if(oks[next]){
        dp[next] += dp[now];
        dp[next] %= mod;
      }
    }
  }

  cout << dp[N] << endl;

  return 0;
}
