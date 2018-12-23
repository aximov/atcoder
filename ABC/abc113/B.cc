#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int N;
  double T, A;
  cin >> N >> T >> A;
  double H;
  int res;
  double diff = 1000;
  for (int i = 1; i <= N; ++i) {
    cin >> H;
    double diff_tmp = fabs(T - H * 0.006 - A);
    if (diff_tmp < diff) {
      diff = diff_tmp;
      res = i;
    }
  }
  cout << res << endl;

  return 0;
}
