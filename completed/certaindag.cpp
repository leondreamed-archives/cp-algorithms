#include <bits/stdc++.h>
using namespace std;
const int n = 6;
const int inf = 0x3f3f3f3f;
vector<int> adj[n+1] = {
  {},
  {2},
  {3},
  {6},
  {1, 5},
  {2, 3}
};

int numpaths[n+1];
short visitstate[n+1];
int expectedpaths[n+1];
bool certain[n+1];

vector<int> dag;

void dfs(int s) {
  if (visitstate[s] == 1) {
    cout << "Not a DAG.\n";
    exit(0);
  }
  visitstate[s] = 1;
  for (int u : adj[s]) {
    if (visitstate[u] != 2) dfs(u);
  }
  dag.push_back(s);
  visitstate[s] = 2;
}

int main() {
  for (int i = 1; i <= n; ++i) if (visitstate[i] != 2) dfs(i);
  reverse(dag.begin(), dag.end());

  int totalpaths = 1;
  
  numpaths[*dag.begin()] = 1;
  for (auto u : dag) {
    for (auto k : adj[u]) {
      numpaths[k] += numpaths[u];
    } 
    expectedpaths[u] = totalpaths;
    totalpaths += max(0UL, adj[u].size() - 1);
  }


  for (auto u : dag) if (numpaths[u] == expectedpaths[u]) certain[u] = true;
  for (int i = 1; i <= n; ++i) cout << certain[i] << " ";
  cout << endl;
}