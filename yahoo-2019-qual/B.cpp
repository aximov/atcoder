#include <iostream>
#include <set>

using namespace std;

int main() {
  int a, b;
  int flg1 = 0, flg2 = 0, flg3 = 0, flg4 = 0;
  for (int i = 0; i < 3; ++i) {
    cin >> a >> b;
    switch (a) {
      case 1:
        ++flg1;
        break;
      case 2:
        ++flg2;
        break;
      case 3:
        ++flg3;
        break;
      case 4:
        ++flg4;
        break;
    }

    switch (b) {
      case 1:
        ++flg1;
        break;
      case 2:
        ++flg2;
        break;
      case 3:
        ++flg3;
        break;
      case 4:
        ++flg4;
        break;
    }
  }
  if (flg1 > 2 || flg2 > 2 || flg3 > 2 || flg4 > 2) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}