#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  int sum = 0;
  int longest = 0;
  for (int i = 0; i < N; ++i) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    if (tmp > longest) longest = tmp;
  }

  sum -= longest;

  if(longest < sum) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}