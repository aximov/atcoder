#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> restaurant_point; // id --> point
  multimap<string, int> restaurant_location; // city name --> ids
  set<string> locations;

  string S;
  int P;
  for (int i = 0; i < N; ++i) {
    cin >> S >> P;
    restaurant_point.push_back(P);
    restaurant_location.insert(make_pair(S, i));
    locations.insert(S);
  }

  for (auto l: locations){
    map<int, int, greater<>> point_id;
    while(true) {
      auto itr = restaurant_location.find(l);
      if (itr == restaurant_location.end()) {
        break;
      } else {
        point_id.insert(make_pair(restaurant_point[itr->second], itr->second));
        restaurant_location.erase(itr);
      }
    }
    for (auto e: point_id) {
      cout << e.second + 1 << endl;
    }
  }

  return 0;
}