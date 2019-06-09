#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

long long dp[1100];
int N;

long long dfs(int here, int n){
  // メモを見る
  if (dp[here] >= 0) {
    return dp[here];
  }

  long long res = 0;

  // 終了
  if (here == n) {
    return dp[here] = 1;
  }

  // 行き過ぎ
  if (here > n) return dp[here] = 0;


  // 次 1段
  res += dfs(here + 1, n);

  // 次 2段
  res += dfs(here + 2, n);

  return dp[here] = res%1000000007;
}

int main() {
  memset(dp, -1, sizeof(dp));
  int M;
  cin >> N >> M;

  int _a;
  for(int i = 0; i < M; ++i) {
    cin >> _a;
    dp[_a] = 0;
  }

  cout << dfs(0,N)%1000000007 << endl;

  return 0;
}