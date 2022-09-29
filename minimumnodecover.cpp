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
vector<int> adj[MAX+1];
vector<Edge> umadj[2*(MAX+1)], *madj = &umadj[MAX];
bool uvisited[2*(MAX+1)], *visited = &uvisited[MAX];
int state[MAX+1];

bool dag(int s) {
  state[s] = 1;
  for (int u : adj[s])
    if (state[u] == 1 || !dag(u)) return false;
  state[s] = 2;
  return true;
}

void pdfs(int s, vector<int> &path) {
  path.push_back(-s);
  visited[-s] = visited[s] = true;
  for (Edge &e : madj[s]) {
    if (e.flow == 0 || visited[-e.to]) continue;
    e.flow = 0;
    pdfs(-e.to, path);
  }
}

bool dfs(int s, int &minf) {
  int ominf = minf;
  visited[s] = true;
  for (Edge &e : madj[s]) {
    int &t = e.to, &f = e.flow, &r = e.rev;
    if (!visited[t] && f >= 1) {
      minf = min(minf, f);
      if (t == MAX || dfs(t, minf)) {
        if (t == MAX) total += minf;
        f -= minf;
        madj[t][r].flow += minf;
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
    madj[-a].push_back(Edge(b, 1, madj[b].size()));
    madj[b].push_back(Edge(-a, 0, madj[-a].size()-1, true));
  }

  for (int i = 1; i <= N; ++i)
    if (state[i] != 2 && !dag(i)) {cout << "Graph is not a DAG.\n"; return 0;}

  for (int i = 1; i <= N; ++i) {
    madj[-MAX].push_back(Edge(-i, 1, madj[-i].size()));
    madj[-i].push_back(Edge(-MAX, 0, madj[-MAX].size()-1, true));
    madj[i].push_back(Edge(MAX, 1, madj[MAX].size()));
    madj[MAX].push_back(Edge(i, 0, madj[i].size()-1, true));
  }

  int minf;
  do {
    minf = inf;
    memset(uvisited, false, sizeof(uvisited));
  } while (dfs(-MAX, minf));
  
  for (int i = -N; i < 0; ++i) {
    for (Edge &e : madj[i]) {
      if (e.flow != 0 || e.isrev) e.flow = 0;
      else e.flow = 1;
    }
  }

  memset(uvisited, false, sizeof(uvisited));
  for (int i = 1; i <= N; ++i) {
    if (visited[-i]) continue;
    vector<int> path;
    pdfs(-i, path);
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }


}