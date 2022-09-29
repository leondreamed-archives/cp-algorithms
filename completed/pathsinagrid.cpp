#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int grid[n+1][n+1] = {
  {0, 0, 0, 0, 0, 0},
  {0, 3, 7, 9, 2, 7},
  {0, 9, 8, 3, 5, 5},
  {0, 1, 7, 9, 8, 5},
  {0, 3, 8, 6, 4, 10},
  {0, 6, 3, 9, 7, 8}
};
int dp[n+1][n+1];

int main() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    }
  }
  cout << dp[n][n] << endl;
}