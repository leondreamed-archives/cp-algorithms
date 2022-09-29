#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int flow;
  int rev;
  bool isrev;
  Edge(int t, int f, int r, bool i = false) : to(t), flow(f), rev(r), isrev(i) {}
};

const int MAX = 1000, inf = 0x3f3f3f3f;
int N, M, total;
vector<Edge> uadj[2*(MAX+1)], *adj = &uadj[MAX];
vector<int> cadj[MAX+1];
bool uvisited[2*(MAX+1)], *visited = &uvisited[MAX];
char state[MAX+1];

bool dfs(int s, int& minf) {
  int ominf = minf;
  visited[s] = true;
  for (Edge &e : adj[s]) {
    int &t = e.to, &f = e.flow, &r = e.rev;
    if (visited[t] || f < 1) continue;
    minf = min(minf, f);
    if (t == MAX || dfs(t, minf)) {
      if (t == MAX) total += minf;
      f -= minf;
      adj[t][r].flow += minf;
      return true;
    } else minf = ominf;
  }
  return false;
}

bool cdfs(int s) {
  state[s] = 1;
  for (int u : cadj[s]) {
    if (state[u] == 1) return false;
    if (state[u] != 2) if (!cdfs(u)) return false;
  }
  state[s] = 2;
  return true;
}

void mdfs(int o, int s) {
  for (int u : cadj[s]) {
    adj[-o].push_back(Edge(u, 1, adj[u].size()));
    adj[u].push_back(Edge(-o, 0, adj[-o].size()-1, true));
    mdfs(o, u);
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0, a, b, c; i < M; ++i) {
    cin >> a >> b >> c;
    cadj[a].push_back(b);
  }

  for (int i = 1; i <= N; ++i) if (state[i] != 2 && !cdfs(i)) {cout << "Graph is not a DAG.\n"; return 0;}

  for (int i = 1; i <= N; ++i) mdfs(i, i);

  for (int i = 1; i <= N; ++i) {
    adj[-MAX].push_back(Edge(-i, 1, adj[-i].size()));
    adj[-i].push_back(Edge(-MAX, 0, adj[-MAX].size()-1, true));
    adj[i].push_back(Edge(MAX, 1, adj[MAX].size()));
    adj[MAX].push_back(Edge(i, 0, adj[i].size()-1, true));
  }

  int minf;
  do {
    minf = inf;
    memset(uvisited, false, sizeof(uvisited));
  } while (dfs(-MAX, minf));

  cout << total << '\n';
}