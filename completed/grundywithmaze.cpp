// Runs in O(n^3logn) time

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int MAX = 1001, inf = 0x3f3f3f3f;
bool maze[MAX][MAX];
int state[MAX][MAX];
int N;

int mex(vector<int> &v) {
  sort(v.begin(), v.end());
  auto it = unique(v.begin(), v.end());
  v.resize(distance(v.begin(), it));
  if (v.empty() || v.front() != 0) return 0;
  for (int i = 1; i < v.size(); ++i)
    if (v[i] - v[i-1] != 1) return v[i-1] + 1;
  return v.back() + 1;
}

void grundyv() {
  vector<int> v;
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      if (maze[y][x]) {state[y][x] = inf; continue;}
      v.clear();
      for (int i = y-1; i >= 0; --i) if (maze[i][x]) break; else v.push_back(state[i][x]);
      for (int i = x-1; i >= 0; --i) if (maze[y][i]) break; else v.push_back(state[y][i]);
      state[y][x] = mex(v);
    }
  }
}

void printgrundy() {
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      if (state[y][x] == inf) cout << "# ";
      else cout << state[y][x] << " ";
    }
    cout << '\n';
  }
}

int main() {
  cin >> N;
  for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) cin >> maze[y][x];
  grundyv();
  printgrundy();
}