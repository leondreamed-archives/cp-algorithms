#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

struct Edge {
  int to;
  int flow;
  int rev;
  bool isrev;
  Edge(int t, int f, int r, bool i = false) : to(t), flow(f), rev(r), isrev(i) {}
};

const int MAX = 2500;
bool visited[MAX+1];
vector<Edge> adj[MAX+1];

int N, M, C = 1, total;

bool dfs(int s, int& minf) {
  int ominf = minf;
  visited[s] = true;
  for (Edge &e : adj[s]) {
    int &t = e.to, &f = e.flow, &r = e.rev;
    if (visited[t] || f < C) continue;
    minf = min(minf, f);
    if (t == N || dfs(t, minf)) {
      if (t == N) total += minf;
      f -= minf;
      adj[t][r].flow += minf;
      return true;
    } else minf = ominf;
  }
  return false;
}

bool pdfs(int s, vector<int> &path) {
  visited[s] = true;
  if (s == N) {path.push_back(s); return true;}
  for (Edge &e : adj[s]) {
    if (visited[e.to] || e.flow == 0) continue;
    if (pdfs(e.to, path)) {e.flow = 0; path.push_back(s); return true;}
  }
  return false;
}

int main() {
  cin >> N >> M;
  for (int i = 0, a, b, c; i < M; ++i) {
    cin >> a >> b >> c;
    Edge ab(b, 1, adj[b].size());
    Edge ba(a, 0, adj[a].size(), true);
    adj[a].push_back(ab);
    adj[b].push_back(ba);
  }

  int minf;
  do {
    memset(visited, false, sizeof(visited));
    minf = inf;
  }
  while (dfs(1, minf));

  for (int i = 1; i <= N; ++i) {
    for (Edge &e : adj[i]) {
      if (e.isrev || e.flow != 0) e.flow = 0;
      else e.flow = 1;
    }
  }

  for (int i = 0; i < total; ++i) {
    memset(visited, false, sizeof(visited));
    vector<int> path;
    pdfs(1, path);
    copy(path.rbegin(), path.rend(), ostream_iterator<int>(cout, " ")); cout << '\n';
  }

  cout << "Number of edge-disjoint paths: " << total << '\n'; 
}