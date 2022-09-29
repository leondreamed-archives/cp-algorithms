#include <bits/stdc++.h>
using namespace std;

const int n = 5;
const int inf = 0xabababa;
int fw[n+1][n+1];

int adj[n+1][n+1] = {
//       0  1  2  3  4  5 <- end
/* 0 */ {0, 0, 0, 0, 0, 0},
/* 1 */ {0, 0, 5, 0, 9, 1},
/* 2 */ {0, 5, 0, 2, 0, 0},
/* 3 */ {0, 0, 2, 0, 7, 0},
/* 4 */ {0, 9, 0, 7, 0, 2},
/* 5 */ {0, 1, 0, 0, 2, 0}
/* start */
};

int main() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) fw[i][j] = 0;
      else if (adj[i][j]) fw[i][j] = adj[i][j];
      else fw[i][j] = inf;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
      }
      cout << fw[i][j] << " ";
    }
    cout << endl;
  }
}