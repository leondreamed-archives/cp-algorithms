#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int parent[N+1];
int level[N+1];
vector<int> tree[N+1] = {
  {},
  {2, 3, 4},
  {5, 6},
  {},
  {7},
  {},
  {8}
};

void dfs(int s, int l) {
  level[s] = l;
  for (auto u : tree[s]) {
    parent[u] = s;
    dfs(u, l+1);
  }
}

int lca(int a, int b) {
  if (level[a] > level[b]) swap(a, b);
  while (level[b] != level[a]) b = parent[b];
  while (a != b) {
    a = parent[a];
    b = parent[b];
  }
  return a;
}

int main() {
  dfs(1, 1);
  cout << lca(1, 3) << endl;
}