#include <iostream>
#include <set>
#include <vector>

#define NMAX 100005
#define KMAX 100005
#define DIAGONAL 1
#define TOP 0

using namespace std;

struct Sushi {
  int type, umaaji;
};

struct masu {
  long long umascore;
  set<int> types;
};

int N, K;
Sushi sushii[NMAX + 1];
masu C[NMAX + 1][KMAX + 1];

void compute(long long &maxValue) {
  for (int k = 0; k <= K; ++k) {
    C[0][k].umascore = 0;
  }

  for (int i = 1; i <= N; ++i) C[i][0].umascore = 0;

  for (int i = 1; i <= N; ++i) {
    for (int k = 1; k <= K; ++k) {
      C[i][k] = C[i - 1][k];
      set<int> tmptypes = C[i - 1][k - 1].types;
      tmptypes.insert(sushii[i].type);
      if (sushii[i].umaaji + C[i - 1][k - 1].umascore +
              tmptypes.size() * tmptypes.size() >
          C[i - 1][k].umascore +
              C[i - 1][k].types.size() * C[i - 1][k].types.size()) {
        C[i][k].umascore = sushii[i].umaaji + C[i - 1][k - 1].umascore;
        C[i][k].types = tmptypes;
      }
    }
  }

  maxValue = C[N][K].umascore + C[N][K].types.size() * C[N][K].types.size();
}

int main() {
  cin >> N >> K;

  for (int i = 1; i <= N; ++i) {
    cin >> sushii[i].type >> sushii[i].umaaji;
  }
  long long res;
  compute(res);
  cout << res << endl;
  return 0;
}