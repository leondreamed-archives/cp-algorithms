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
bool visited[n+1];
bool final[n+1];
vector<int> topsort;

bool dfs(int u) {
  if (visited[u]) return false;
  if (final[u]) return true;
  visited[u] = true;
  for (auto d : adj[u]) {
    if (!dfs(d)) return false;
  }
  
  topsort.push_back(u);
  visited[u] = false;
  return final[u] = true;
}

int minedges[n+1];

int main() {
  for (int i = 1; i <= n; ++i) {
    minedges[i] = inf;
    if (!final[i])
      if (!dfs(i)) {cout << "not a dag"; return 0;} 
  }
  reverse(topsort.begin(), topsort.end());

  minedges[*topsort.begin()] = 0;
  for (auto u : topsort) {
    for (auto e : adj[u]) {
      minedges[e] = min(minedges[e], minedges[u] + 1);
    }
  }

  for (auto u : topsort) {
    cout << minedges[u] << " ";
  }

}