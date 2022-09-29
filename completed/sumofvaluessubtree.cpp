#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int order[N+1];
int ni[N+1]; // node id
int ssum[N+1]; // subtree sum
int siz[N+1]; // subtree size
int values[N+1] = {0, 2, 3, 5, 3, 1, 4, 4, 3, 1};
int bit[N+1];
vector<int> tree[N+1] = {
  {},
  {2, 3, 4, 5},
  {6},
  {},
  {7, 8, 9}
};

void dfs(int s, int &i) {
  int oi = i;
  ni[oi] = s;
  ssum[oi] = values[s];
  int sz = 1;
  for (auto u : tree[s]) {
    int idx = i+1;
    dfs(u, ++i);
    sz += siz[idx];
  }
  siz[oi] = sz;
}

void add(int k, int x) {
  while (k <= N) {
    bit[k] += x;
    k += k&-k;
  }
}

int sum(int k) {
  int s = 0;
  while (k > 0) {
    s += bit[k];
    k -= k&-k;
  }
  return s;
}

int sum(int a, int b) {
  return sum(b) - sum(a-1);
}

int main() {
  int index = 1;
  dfs(1, index);
  for (int i = 1; i <= N; ++i) add(i, ssum[i]);
  for (auto b : bit) cout << b << " "; cout << endl;
}