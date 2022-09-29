#include <bits/stdc++.h>
using namespace std;

const int n = 7;
vector<int> adj[n+1] = {
  {},
  {2, 3, 4},
  {5},
  {},
  {7},
  {6}
};

void dfs(int s, int e, int dist, int& maxdist, int& maxnode, int& maxparent) {
  if (dist > maxdist) {maxdist = dist, maxnode = s, maxparent = e;}
  for (auto u : adj[s]) {
    if (u != e) {
      dfs(u, s, dist + 1, maxdist, maxnode, maxparent);
    }
  }
}

int main() {
  // making tree double bi-directional
  for (int i = 1; i <= n; ++i) {
    for (auto u : adj[i]) {
      adj[u].push_back(i);
    }
    // copy(adj[i].begin(), adj[i].end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
  }

  int b, c, maxb, maxc, pb, pc;
  b = c = maxb = maxc = pb = pc = 0;
  dfs(1, 0, 0, maxb, b, pb); // find furthest node from 1 (arbitrary node)
  dfs(b, 0, 0, maxc, c, pc); // find furthest node from b
  cout << maxc << endl;

}