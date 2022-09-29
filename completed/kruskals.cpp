#include <bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm

vector<tuple<int, int, int>> edges = {
  {1, 2, 3},
  {1, 5, 5},
  {2, 5, 6},
  {2, 3, 5},
  {3, 6, 3},
  {3, 4, 9},
  {4, 6, 7},
  {5, 6, 2}
};
int n = 6;

vector<int> link;
vector<int> size;

int find(int k) {
  while (link[k] != k) k = link[k];
  return k;
}

bool same(int a, int b) {
  return find(a) == find(b);
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (size[a] < size[b]) swap(a, b);
  link[b] = a;
  size[a] += size[b];
}

int main() {
  link.resize(n + 1);
  size.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    size[i] = 1;
   link[i] = i;
  }
  sort(edges.begin(), edges.end(),
  [](tuple<int,int,int> &t, tuple<int,int,int> &u){return get<2>(t) < get<2>(u);});
  int a, b, w, weight = 0;
  for (auto e : edges) {
    tie(a,b,w) = e;
    if (!same(a,b)) {
      cout << a << " " << b << endl;
      unite(a,b);
      weight += w;
    }
  }
  
  cout << weight;
}