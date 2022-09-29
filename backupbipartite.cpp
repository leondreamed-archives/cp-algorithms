#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int flow;
  int rev;
  bool isrev;
  Edge(int t, int f, int r, bool i = false) : to(t), flow(f), rev(r), isrev(i) {};
};

const int inf = 0x3f3f3f3f;
const int MAX = 100000;
bool marked[MAX+2];
bool visited[MAX+2];
vector<Edge> adj[MAX+2];
vector<int> badj[MAX+2];

int N, M, total;

bool bidfs(int s, bool c) {
  visited[s] = true;
  marked[s] = c;
  for (int u : badj[s]) {
    if (visited[u] && marked[u] == c) return false;
    if (!visited[u] && !bidfs(u, !c)) return false;
  }
  return true;
}

bool dfs(int s, int& minf) {
  int ominf = minf;
  visited[s] = true;
  for (Edge &e : adj[s]) {
    int &t = e.to, &f = e.flow, &r = e.rev;
    if (!visited[t] && f >= 1) {
      minf = min(minf, f);
      if (t == N+1 || dfs(t, minf)) {
        if (t == N+1) total += minf;
        f -= minf;
        adj[t][r].flow += minf;
        return true;
      } else minf = ominf;
    }
  }
  return false;
}

bool pdfs(int s, vector<int> &path) {
  visited[s] = true;
  if (s == N+1) return true;
  for (Edge &e : adj[s]) {
    if (!visited[e.to] && e.flow >= 1) {
      if (pdfs(e.to, path)) {
        e.flow = 0;
        if (s) path.push_back(s);
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> N >> M;
  for (int i = 0, a, b; i < M; ++i) {
    cin >> a >> b;
    badj[a].push_back(b);
    badj[b].push_back(a);
  }

  for (int i = 1; i <= N; ++i) {
    if (!visited[i] && !bidfs(i, true)) {
      cout << "Graph is not bipartite.\n"; return 0;
    }
  }

  for (int a = 1; a <= N; ++a) {
    if (!marked[a]) {
      adj[a].push_back(Edge(N+1, 1, adj[N+1].size()));
      adj[N+1].push_back(Edge(a, 0, adj[a].size()-1, true));
      continue;
    }
    adj[0].push_back(Edge(a, 1, adj[a].size()));
    adj[a].push_back(Edge(0, 0, adj[0].size()-1, true));
    for (int b : badj[a]) {
      Edge ab(b, 1, adj[b].size());
      Edge ba(a, 0, adj[a].size(), true);
      adj[a].push_back(ab);
      adj[b].push_back(ba);
    }
  }

  int minf;
  do {
    minf = inf;
    memset(visited, false, sizeof(visited));
  } while (dfs(0, minf));

  cout << total;
  return 0;

  for (int i = 0; i <= N+1; ++i) {
    for (Edge &e : adj[i]) {
      if (e.isrev || e.flow != 0) e.flow = 0;
      else e.flow = 1;
    }
  }

  for (int i = 0; i < total; ++i) {
    vector<int> path;
    memset(visited, false, sizeof(visited));
    pdfs(0, path);
    copy(path.rbegin(), path.rend(), ostream_iterator<int>(cout, " ")); cout << '\n';
  }
  
  cout << "Maximum number of matchings is: " << total << '\n';
}