#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vector : public vector<T> {
 public:
  Vector(initializer_list<T> l) : vector<T>(l) {}
  T& operator[](int i) {
    if (i < 0)
      return vector<T>::operator[](this->size() + i);
    else if (i >= this->size())
      return vector<T>::operator[](i - this->size());
    else
      return vector<T>::operator[](i);
  }
};

int main() {
  int L, N;
  Vector<int> X{};
  cin >> L >> N;
  X.push_back(-1);
  for (int i = 0; i < N; ++i) {
    int tmp;
    cin >> tmp;
    X.push_back(tmp);
  }

  long long distance = 0;

  int xi = 0;
  int i = 0;
  int d_ccw = 0;
  int d_cw = 0;
  int next_ccw_val = 0;
  int next_cw_val = 0;
  int next_ccw_pos = 0;
  int next_cw_pos = 0;
  while (N != 0) {
    for (int ccw = i + 1;; ++ccw) {
      if (X[ccw] != -1) {
        next_ccw_pos = ccw;
        next_ccw_val = X[ccw];
        break;
      }
    }
    for (int cw = i - 1;; --cw) {
      if (X[cw] != -1) {
        next_cw_pos = cw;
        next_cw_val = X[cw];
        break;
      }
    }

    d_ccw = next_ccw_val - xi;
    if (d_ccw < 0) d_ccw += L;

    d_cw = xi - next_cw_val;
    if (d_cw < 0) d_cw += L;

    X[i] = -1;
    --N;
    if (d_ccw > d_cw) {
      i = next_ccw_pos;
      xi = next_ccw_val;
      distance += d_ccw;
    } else {
      i = next_cw_pos;
      xi = next_cw_val;
      distance += d_cw;
    }
  }

  cout << distance << endl;
  return 0;
}