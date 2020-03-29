#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  long long N, K;
  cin >> N >> K;
  vector<long long> a;
  int _a;
  for(long long i = 0; i < N; ++i) {
    cin >> _a;
    a.push_back(_a);
  }

  long long cnt = 0;
  long long begin = 0, end = 0;
  long long sum = 0;
  for(;;) {
    while (end < N && sum < K) {
      sum += a[end];
      end++;
    }
    if(sum < K) break;
    cnt += 1 + max(0LL, N - 1 - (end - 1));

    sum -= a[begin];
    begin++;
  }

  cout << cnt << endl;

  return 0;
}