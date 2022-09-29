#include <bits/stdc++.h>

using namespace std;

// using map because some values may be negative
// representing not x as -x
map<int, vector<int>> adj;
map<int, bool> visited;
map<int, int> link;
vector<set<int>> cadj;
vector<vector<int>> components;
vector<pair<int, int>> states = {
  // {2, -1}, {-1, -2}, {1, 3}, {-2, -3}, {1, 4}
  {1, 2}, {1, -2}, {-1, 3}, {-1, -3}
};



void connectifpos(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  cadj[b].insert(a);
}

int find(int x) {
  while (x != link[x]) x = link[x];
  return x;
}

void dfs(int k, stack<int> &s) {
  visited[k] = true;
  for (int &u : adj[k]) {
    if (!visited[u]) dfs(u, s);
  }
  s.push(k);
}

void dfs(int k, vector<int> &c) {
  c.push_back(k);
  visited[k] = true;
  for (int &u : adj[k]) {
    if (!visited[u]) dfs(u, c);
  }
}

int main() {
  for (pair<int, int> &p : states) {
    // if not x then y, x -> y
    adj[-p.first].push_back(p.second);
    // if not y then x, y -> x
    adj[-p.second].push_back(p.first);
  }

  // using kosaraju's algorithm
  stack<int> s;
  for (auto &p : adj) {
    if (!visited[p.first]) dfs(p.first, s);
  }

  

  {
    // reversing all edges
    map<int, vector<int>> radj;
    for (auto &p : adj) {
      for (auto &u : p.second) {
        radj[u].push_back(p.first);
      }
    }
    adj = move(radj);
  }

  for (auto &p : visited) p.second = false;
  vector<int> c;

  while (!s.empty()) {
    auto p = s.top(); s.pop();
    if (visited[p]) continue;
    dfs(p, c);
    components.push_back(move(c));
    c.clear();
  }

  for (auto &v : components) {
    sort(v.begin(), v.end());
    auto beg = v.begin();
    auto end = v.end() - 1;
    while (beg < end) {
      if (*beg + *end == 0) {
        goto npos;
      } else if (*beg + *end < 0) {
        ++beg;
      } else if (*beg + *end > 0) {
        --end;
      }
    }
  }

  cout << "Possible.\n";

  // Creating a unite method like Kruskals'
  // the top of all strongly connected components is the first element
  for (auto &v : components) {
    // the root of all linked elements in v
    for (int i = 0; i < v.size(); ++i) link[v[i]] = v[0];
  }

  // To unite all components, loop through the adjacency list and check
  // if the edge extends to another component. If so, connect the two components
  for (int i = 1; i <= n; ++i) {
    for (auto &j : v) {
      connectifpos(i, j);
    }
  }

  

  return 0;
  npos: cout << "Not Possible.\n";
  
}