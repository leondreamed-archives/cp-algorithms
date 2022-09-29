#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int flow;
  int rev;
  bool isrev;
  Edge(int t, int f, int r, int i = false) : to(t), flow(f), rev(r), isrev(i) {};
};

const int inf = 0x3f3f3f3f;
const int MAX = 1000;
vector<Edge> uadj[(MAX+1)*2], *adj = &uadj[MAX];
bool uvisited[(MAX+1)*2], *visited = &uvisited[MAX];

int N, M, total;

bool dfs(int s, int& minf) {
  int ominf = minf;
  visited[s] = true;
  for (Edge &e : adj[s]) {
    int &t = e.to, &f = e.flow, &r = e.rev;
    if (!visited[t] && f >= 1) {
      minf = min(minf, f);
      if (t == -N || dfs(t, minf)) {
        if (t == -N) total += minf;
        f -= minf;
        adj[t][r].flow += minf;
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
    Edge ab(-b, inf, adj[-b].size());
    Edge ba(a, 0, adj[a].size(), true);
    adj[a].push_back(ab);
    adj[-b].push_back(ba);
  }

  for (int i = 2; i < N; ++i) {
    Edge a(i, 1, adj[i].size());
    Edge b(-i, 0, adj[-i].size(), true);
    adj[i].push_back(b);
    adj[-i].push_back(a);
  }

  int minf;
  do {
    minf = inf;
    memset(uvisited, false, sizeof(uvisited));
  } while (dfs(1, minf));

  
}