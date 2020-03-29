#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N,X;
  cin >> N >> X;
  vector<int> L;
  int _l;
  for (int i = 0; i < N; ++i) {
    cin >> _l;
    L.push_back(_l);
  }
  int position = 0;
  int cnt = 0;
  while (position <= X && cnt < N + 1){
    position += L[cnt];
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}