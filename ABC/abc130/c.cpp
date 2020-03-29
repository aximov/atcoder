#include <iostream>
#include <vector>

using namespace std;

int main(){
  double W,H,x,y;
  cin >> W >> H >> x >> y;
  int multiple = 0;
  if (x == W/2.0 && y == H/2.0) multiple = 1;
  cout << multiple << endl;
  return 0;
}