#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int n_of_1 = 0, n_of_2 = 0, n_of_3 = 0;
  int p;
  while (cin >> p) {
    if (p <= A)
      ++n_of_1;
    else if (p <= B)
      ++n_of_2;
    else
      ++n_of_3;
  }
  int res = min(n_of_1, n_of_2);
  res = min(res, n_of_3);
  cout << res << endl;
  return 0;
}