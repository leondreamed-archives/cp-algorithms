#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n+1] = {
  {},
  {2, 4},
  {1, 3, 5},
  {2, 6},
  {1},
  {2, 6},
  {3, 5}
};
int dist[n+1];
bool visited[n+1];
const int inf = 0x3f3f3f3f;

int main() {
  for (int i = 1; i <= n; ++i) dist[i] = inf;
  dist[1] = 0;
  queue<int> nodes;
  nodes.push(1);
 visited[1] = true;
  while (!nodes.empty()) {
    int cur = nodes.front(); nodes.pop();
    for (auto &u : adj[cur]) {
      if (visited[u]) continue;
      visited[u] = true;
      nodes.push(u);
      dist[u] = dist[cur]+1;
    }
  }

  for (auto &d : dist) {
    cout << d << " ";
  }
  cout << endl;
}