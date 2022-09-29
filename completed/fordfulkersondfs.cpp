#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3ababab;
const int n = 6;

// index = start node, params = end node, current flow, pointer to reverse path
struct Path {
  int end;
  int flow;
  Path* rev;
  Path(int e, int f, Path* r) {
    end = e, flow = f, rev = r; 
  }
};

vector<Path*> adj[n+1] = {
  {},
  {new Path(2, 5, nullptr), new Path(4, 4, nullptr)},
  {new Path(3, 6, nullptr)},
  {new Path(5, 8, nullptr), new Path(6, 5, nullptr)},
  {new Path(2, 3, nullptr), new Path(5, 1, nullptr)},
  {new Path(6, 2, nullptr)},
  {}
};

int flow = 0;
bool visited[n+1];

// returns whether or not path makes it to sink
bool dfs(int s, int& mw) {
  visited[s] = true;
  for (Path* u : adj[s]) {
    if (u->end == n && u->flow > 0) { // if path directly links to sink
      mw = min(u->flow, mw);
      flow += mw;
      u->flow -= mw;
      u->rev->flow += mw;
      visited[s] = false;
      return true;
    } else if (!visited[u->end] && u->flow > 0) {
      int omw = mw; // creating min weight backup
      mw = min(u->flow, mw);
      bool r = dfs(u->end, mw);
      if (r) { // if path leads to sink
        u->flow -= mw;
        u->rev->flow += mw;
        visited[s] = false;
        return true;
      } else {
        mw = omw; // restore backup
      }
    }
  }  

  return false; // could not find any valid paths
}

void printadj() {
  for (auto &v : adj) {
    for (auto &i : v) {
      cout << i->end << "," << i->flow << " ";
    }
    cout << endl;
  }
}

int main() {
  for (int i = 1, j = 0; i <= n; ++i) {
    for (Path* u : adj[i]) {
      if (u->flow == 0) break;
      Path *np = new Path(i, 0, u);
      u->rev = np;
      adj[u->end].push_back(np);
    }
  }
  
  bool r;
  int m = inf;
  while ((r = dfs(1, m))) {
    memset(visited, false, sizeof(visited));
    m = inf;
  }
  cout << flow << endl;
}
