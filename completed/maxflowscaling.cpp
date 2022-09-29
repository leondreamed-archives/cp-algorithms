#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAX = 5000;
bool visited[MAX+1];
vector<int> adj[MAX+1];
vector<int> capacity[MAX+1];
int flow[MAX+1][MAX+1];
int N, M, C, total;

bool dfs(int s, int &minf) {
  int ominf = minf;
  visited[s] = true;
  for (int i = 0; i < adj[s].size(); ++i) {
    int u = adj[s][i];
    if (visited[u]) continue;
    if (capacity[s][i] - flow[s][u] >= C) {
      minf = min(minf, capacity[s][i] - flow[s][u]);
      if (u == N || dfs(u, minf)) {
        if (u == N) total += minf;
        flow[s][u] += minf;
        flow[u][s] -= minf;
        return true;
      } else minf = ominf;
    }
  }
  return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0, a, b, c; i < M; ++i) {
      cin >> a >> b >> c;
      adj[a].push_back(b);
      adj[b].push_back(a);
      capacity[a].push_back(c);
      capacity[b].push_back(c);
      C = max(C, c);
    }

    int minf;
    do {
      do {
        fill(visited+1, visited+N+1, false);
        minf = inf;
      } while (dfs(1, minf));
    } while (C /= 2);

    cout << total << '\n';
}
