#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int inf = 0x3f3f3f3f;
const int64_t linf = 0x3f3f3f3f;
typedef int64_t lg;
typedef pair<int, int> pii;

struct Edge {
  int to;
  int flow;
  int rev;
  bool isrev;
  Edge(int t, int f, int r, bool i = false) : to(t), flow(f), rev(r), isrev(i) {}
};

int N, M;
const int MAX = 100000;
bool mark[MAX+2];
bool visited[MAX+2];
vector<int> cadj[MAX+2];
vector<Edge> adj[MAX+2];
int flow;

bool bdfs(int s, int e) {
  visited[s] = true; mark[s] = !mark[e];
  for (int u : cadj[s]) {
    if (visited[u] && mark[u] == mark[s]) return false;
    if (!visited[u]) bdfs(u, s);
  }
  return true;
}

bool dfs(int s, int &minf) {
  int ominf = minf;
  visited[s] = true;
  for (Edge &e : adj[s]) {
    int &t = e.to, &f = e.flow, &r = e.rev;
    if (visited[t] || f < 1) continue;
    minf = min(minf, f);
    if (t == N+1 || dfs(t, minf)) {
      if (t == N+1) flow += minf;
      f -= minf;
      adj[t][r].flow += minf;
      return true;
    } else minf = ominf;
  }
  return false;
}

int main() {
  // get input from a bipartite graph
  scan(N); scan(M);
  for (int i = 0, a, b; i < M; ++i) {
    scan(a); scan(b);
    cadj[a].push_back(b);
    cadj[b].push_back(a);
  }

  vector<int> path;
  for (int s = 1; s <= N; ++s) {
    if (!visited[s] && !bdfs(s, 0)) {cout << "Graph is not bipartite.\n"; return 0;}
  }

  for (int i = 1; i <= N; ++i) {
    if (mark[i]) {
      adj[0].push_back(Edge(i, 1, adj[i].size()));
      adj[i].push_back(Edge(0, 0, adj[0].size()-1));
      for (int u : cadj[i]) {
        adj[i].push_back(Edge(u, 1, adj[u].size()));
        adj[u].push_back(Edge(i, 0, adj[i].size()-1, true));
      }
    } else {
      adj[i].push_back(Edge(N+1, 1, adj[N+1].size()));
      adj[N+1].push_back(Edge(i, 0, adj[i].size()-1));
    }
  }

  int minf;
  do {
    minf = inf;
    memset(visited, false, sizeof(visited));
  } while (dfs(0, minf));

  cout << flow;
  

}