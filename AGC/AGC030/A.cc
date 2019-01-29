#include <iostream>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int cnt = 0;
  if (B >= C) {
    cnt = B + C;
  } else {
    C -= B;
    cnt += B * 2;
    if (C > A) {
      cnt += A + 1;
    } else {
      cnt += C;
    }
  }

  cout << cnt << endl;
  return 0;
}