#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
vector<int> tree[MAX+1];
int depth[MAX+1];
int parent[MAX+1];
int values[MAX+1];

int ss[MAX+1];
int ps[MAX+1];
int ni[MAX+1];
int bk[MAX+1];
int psbit[MAX+1];

int N;

void dfs(int s, int e, int &i, int sm, int d) {
  depth[s] = d;
  parent[s] = e;
  sm += values[s];
  int oi = i;
  bk[s] = oi;
  ni[oi] = s;
  ps[oi] = sm;
  ss[oi] = 1;
  for (int u : tree[s]) {
    int ti = ++i;
    dfs(u, s, i, sm, d+1);
    ss[oi] += ss[ti];
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  while (depth[a] != depth[b]) a = parent[a];
  while (a != b) a = parent[a], b = parent[b];
  return a;
}

int sum(int k) {
  int s = 0;
  while (k > 0) {
    s += psbit[k];
    k -= k&-k;
  }
  return s;
}

void add(int k, int v) {
  while (k <= N) {
    psbit[k] += v;
    k+=k&-k;
  }
}

void update(int x, int v) {
  add(x, v);
  add(x+ss[x], -v);
}

int calc(int a, int b) {
  int c = lca(a, b);
  return sum(bk[a]) + sum(bk[b]) - sum(bk[c]);
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> values[i];
  for (int i = 0, a, b; i < N-1; ++i) {
    cin >> a >> b;
    tree[a].push_back(b);
  }

  int counter = 1;
  dfs(1, 0, counter, 0, 1);

  for (int i = 1; i <= N; ++i) {add(i, ps[i] - ps[i-1]);}

  cout << sum(bk[9]) << '\n';


  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) {
      if (i != j) printf("Path sum between %d and %d = %d\n", i, j, calc(i, j));
    }

}