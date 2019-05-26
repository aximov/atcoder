#include <iostream>

using namespace std;

int main() {
  long long K, A, B;
  cin >> K >> A >> B;
  if (B - A < 3) cout << 1 + K << endl;
  else {
    if (A + 1 > K) cout << 1 + K << endl;
    else {
      long long result = 0;
      result += B;
      K -= A + 1;
      while (K > 0) {
        result -= A;
        result += B;
        K -= 2;
      }
      if (K < 0) {
        result -= B;
        result += A;
        result += 1;
      }
      cout << result << endl;
    }
  }

  return 0;
}

