#include <bits/stdc++.h>
using namespace std;

const int N = 6;
vector<int> adj[N+1] = {
  {},
  {2},
  {3},
  {6},
  {1, 5},
  {2, 3}
};

int totalpaths[N+1];
vector<int> topsort;
bool visited[N+1];
bool finalv[N+1];

bool dfs(int u) {
  if (visited[u]) return false;
  if (finalv[u]) return true;
  for (int n : adj[u]) {
    if (!dfs(n)) return false;
  }
  topsort.push_back(u);
  visited[u] = false;
  finalv[u] = true;
  return true;
}

int main() {
  for (int i = 1; i <= N; ++i) if (!finalv[i]) dfs(i);
  reverse(topsort.begin(), topsort.end());

  totalpaths[*topsort.begin()] = 1;
  for (auto u : topsort) {
    for (auto n : adj[u]) {
      totalpaths[n] += totalpaths[u];
    }
  }

  for (auto u : topsort) cout << totalpaths[u] << " ";
  // copy(topsort.begin(), topsort.end(), ostream_iterator<int>(cout, " "));
}