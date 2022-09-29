#include <bits/stdc++.h>
using namespace std;

const int n = 5;
const int inf = 0x3f3f3f3f;
vector<pair<int, int>> adj[n+1] = {
  {},
  {{2, 3}, {3, 5}},
  {{1, 3}, {3, 2}, {4, 4}, {5, 8}},
  {{1, 5}, {2, 2}, {4, 2}},
  {{2, 4}, {3, 2}, {5, 1}},
  {{2, 8}, {4, 1}}
};

vector<int> dag[n+1];
bool visited[n+1];
int shortestpath[n+1];
vector<int> topsort;
int spath[n+1];

void dfs(int s) {
  if (visited[s]) return;
  visited[s] = true;
  for (int u : dag[s]) {
    dfs(u);
  }
  topsort.push_back(s);
}

int main() {
  memset(shortestpath, inf, sizeof(shortestpath));
  priority_queue<pair<int, int>> q;
  q.push({1, 0});
  shortestpath[1] = 0;
  int s, w;
  while (!q.empty()) {
    tie(s, w) = q.top(); q.pop();
    if (visited[s]) continue;
    visited[s] = true;
    for (pair<int, int> &p : adj[s]) {
      if (shortestpath[s] + p.second > shortestpath[p.first]) continue;
      shortestpath[p.first] = shortestpath[s] + p.second;
      dag[s].push_back(p.first);
      q.push({p.first, -p.second});
    }
  }

  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; ++i) dfs(i);
  reverse(topsort.begin(), topsort.end());

  spath[*topsort.begin()] = 1;

  for (auto i : topsort) {
    for (auto u : dag[i]) {
      spath[u] += spath[i];
    }
  }

  for (int i = 1; i <= n; ++i) cout << spath[i] << " ";

}