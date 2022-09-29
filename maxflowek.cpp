#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAXN = 5000;
vector<int> capacity[MAXN+1];
vector<int> adj[MAXN+1];
int residual[MAXN+1][MAXN+1];
int path[MAXN+1];
int flow[MAXN+1];
int total;

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0, a, b, c; i < M; ++i) {
    cin >> a >> b >> c;
    adj[a].push_back(b);
    adj[b].push_back(a);
    capacity[a].push_back(c);
    capacity[b].push_back(c);
    residual[b][a] = c;
  }

  while (true) {
    fill(path+1, path+N+1, -1);
    fill(flow+1, flow+N+1, 0);
    flow[1] = inf;
    path[1] = -2;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      int s = q.front(); q.pop();
      for (int i = 0; i < adj[s].size(); ++i) {
        int u = adj[s][i];
        if (capacity[s][i] - residual[s][u] > 0 && path[u] == -1) {
          path[u] = s;
          flow[u] = min(flow[s], capacity[s][i] - residual[s][u]);
          if (u != N) q.push(u);
          else goto end;
        }
      }
    }
    break;

    end:
    total += flow[N];
    int u = N;
    while (u != 1) {
      int v = path[u];
      residual[u][v] -= flow[N];
      residual[v][u] += flow[N];
      u = v;
    }
  }

  cout << total << '\n';
}