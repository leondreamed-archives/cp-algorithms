#include <bits/stdc++.h>
using namespace std;

const int k = 3;
const int n = 8;
const int inf = 0xabababa;
int price[k][n] = {
  {6, 9, 5, 2, 8, 9, 1, 6},
  {8, 2, 6, 2, 7, 5, 7, 2},
  {5, 3, 9, 7, 3, 5, 2, 4}
};
int total[1<<k][n];

int main() {
  for (int i = 0; i < k; ++i) {
    total[1<<i][0] = price[i][0];
  }
  for (int i = 0; i < n; ++i) {
    total[0][i] = 0;
  }

  for (int s = 0, items; s < (1<<k); ++s) {
    if ((items = __builtin_popcount(s)) >= 2) {
      for (int d = 0; d <= items-2; ++d) {
        total[s][d] = inf;
      }
    }
  }

  for (int d = 1; d < n; ++d) {
    for (int s = 0; s < (1 << k); ++s) {
      total[s][d] = total[s][d-1];
      for (int x = 0; x < k; ++x) {
        if (s&(1<<x)) {
          total[s][d] = min(total[s][d], total[s^(1<<x)][d-1] + price[x][d]);
        }
      }
    }
  }

  cout << total[(1<<k)-1][n-1] << endl;
}