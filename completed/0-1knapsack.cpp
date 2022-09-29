#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

template <typename T, size_t N>
constexpr int asum(T const (&a)[N], size_t i = 0U) {
  return i < N ? (a[i] + asum(a, i+1U)) : T{};
}

constexpr int N = 5, C = 28;
constexpr int weights[N] = {1, 5, 20, 1, 7};
constexpr int values[N] = {10, 7, 25, 4, 8};
constexpr int S {asum(values)};

int dp[C+1][N+1];
bool ready[C+1][N+1];

// r = remaining
int solve(int r, int n) {
  int &ret = dp[r][n];
  if (ready[r][n]) return ret;
  ready[r][n] = true;
  if (n == 0) return ret = 0;
  if (r >= weights[n-1]) ret = values[n-1] + solve(r-weights[n-1], n-1);
  return ret = max(ret, solve(r, n-1));
}

int main() {
  cout << solve(C, N) << endl;
}