#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int id[N+1];
int ps[N+1];
int ss[N+1];
int bk[N+1];
int psdiff[N+1];
int psbit[N+1];

vector<int> adj[N+1] = {
  {},
  {2, 3, 4, 5},
  {6},
  {},
  {7, 8, 9}
};
int values[N+1] = {0, 4, 5, 3, 5, 2, 3, 5, 3, 1};

void dfs(int s, int &i, int sm) {
  sm += values[s];
  int oi = i;
  ss[oi] = 1; ps[oi] = sm; id[oi] = s; bk[s] = oi;
  for (int u : adj[s]) {
    int ni = ++i;
    dfs(u, i, sm);
    ss[oi] += ss[ni];
  }
}

int sum(int x) {
  int s = 0;
  while (x > 0) {
    s += psbit[x];
    x -= x&-x;
  }
  return s;
}

void add(int x, int v) {
  while (x <= N) {
    psbit[x] += v;
    x+=x&-x;
  }
}

// update a node's value
void update(int x, int v) {
  add(x, v);
  add(x+ss[x], -v);
}

int main() {
  int counter = 1;
  dfs(1, counter, 0);
  for (int i = 1; i <= N; ++i) psdiff[i] = ps[i] - ps[i-1];
  for (int i = 1; i <= N; ++i) add(i, psdiff[i]);
  for (int i = 1; i <= N; ++i) cout << sum(bk[i]) << ' '; cout << '\n';
  update(bk[4], 1);
  for (int i = 1; i <= N; ++i) cout << sum(bk[i]) << ' '; cout << '\n';
}