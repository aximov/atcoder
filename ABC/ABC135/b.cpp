#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> v;
  int t;
  int N;
  cin >> N;
  while(cin >> t){
    v.push_back(t);
  }
  vector<int> sorted = v;
  sort(sorted.begin(), sorted.end());

  if(v == sorted) {
    cout << "YES" << endl;
    return 0;
  }

  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j){
      vector<int> w = v;
      int a = w[i];
      int b = w[j];

      w[i] = b;
      w[j] = a;

      if(w == sorted) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}