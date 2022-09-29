#include <bits/stdc++.h>
using namespace std;

const int N = 7;

bool visited[N+1];

// adj[i].size() represents degree because graph is undirected
vector<int> adj[N+1] = {
  {},
  {2, 3},
  {1, 3, 5, 6},
  {1, 2, 4},
  {3, 7},
  {2, 6},
  {2, 3, 5},
  {4, 6}
};

void dfs(int s, int &c) {
  visited[s] = true;
  for (int u : adj[s]) if (!visited[u]) dfs(u, ++c);
}

int main() {
  int c = 1;
  dfs(1, c);
  if (c != N) {
    cout << "There are no Eulerian paths because not all nodes belong to the same component.\n";
    return 0;
  }
  
  int oddcount = 0;
  for (int i = 1; i <= N; ++i) {
    if (adj[i].size() % 2 == 1) if (++oddcount > 2) break;
  }

  if (oddcount == 0) cout << "Circuit.";
  else if (oddcount == 2) cout << "Path.";
  else cout << "No path.";
  cout << endl;
}
