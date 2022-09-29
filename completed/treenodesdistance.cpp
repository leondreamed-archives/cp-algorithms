#include <bits/stdc++.h>
using namespace std;

const int N = 9;
vector<int> tree[N+1] = {
  {},
  {2, 3, 4},
  {5, 6},
  {},
  {7},
  {},
  {8}
};
int depth[N+1];
int parent[N+1] = {0, 0, 1, 1, 1, 2, 2, 4, 6};

void dfs(int s, int d) {
  depth[s] = d;
  for (int u : tree[s]) dfs(u, d+1);
}

int calcd(int a, int b) {
  int ta = a, tb = b;
  // getting LCA, assuming a is deeper
  if (depth[b] > depth[a]) swap(a, b);
  while (depth[a] != depth[b]) a = parent[a];
  while (a != b) a = parent[a], b = parent[b];
  return depth[ta] + depth[tb] - 2 * depth[a];
}

int main() {
  dfs(1, 1);
  cout << calcd(5, 8);
}