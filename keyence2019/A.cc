#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  bool f1 = false, f9 = false, f7 = false, f4 = false;
  while (cin >> n) {
    if (n == 1) f1 = true;
    if (n == 9) f9 = true;
    if (n == 7) f7 = true;
    if (n == 4) f4 = true;
  }
  if (f1 && f9 && f7 && f4)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}