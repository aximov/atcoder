#include <iostream>
#include <set>

using namespace std;

int f(int n) {
  if (n % 2 == 0)
    return n / 2;
  else
    return 3 * n + 1;
}

int main() {
  int s;
  cin >> s;

  int res;

  set<int> set;
  set.insert(s);

  int a_prev = s;
  for (int i = 2; i < 1000001; ++i) {
    int a_n;
    a_n = f(a_prev);

    if (set.find(a_n) != set.end()) {
      res = i;
      break;
    } else {
      set.insert(a_n);
      a_prev = a_n;
    }
  }

  cout << res << endl;
  return 0;
}