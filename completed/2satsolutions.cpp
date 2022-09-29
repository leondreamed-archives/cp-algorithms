#include <bits/stdc++.h>
using namespace std;

const int M = 5, N = 4; 
pair<int, int> formula[M] = {
  {2, -1}, {-1, -2}, {1, 3}, {-2, -3}, {1, 4}
};

vector<int> uadj[2*N+1], *adj = &uadj[N];
vector<int> uradj[2*N+1], *radj = &uradj[N];
bool uvisited[2*N+1], *visited = &uvisited[N];
int ucomponent[2*N+1], *component = &ucomponent[N];
vector<int> order;
vector<vector<int>> components;
vector<set<int>> cadj;
vector<int> tsort;
bool answers[N+1];

void dfs(int i, vector<int> &v) {
  visited[i] = true;
  for (int u : adj[i]) {
    if (!visited[u]) dfs(u, v);
  }
  v.push_back(i);
}

void cdfs(int i) {
  visited[i] = true;
  for (int u : adj[i]) {
    if (component[i] != component[u]) cadj[component[i]].insert(component[u]);
    if (!visited[u]) cdfs(u);
  }
}

void topsort(int i) {
  visited[i] = true;
  for (int u : cadj[i]) {
    if (!visited[u]) topsort(u);
  }
  tsort.push_back(i);
}

int main() {
  for (const pair<int, int> &p : formula) {
    adj[-p.first].push_back(p.second);
    adj[-p.second].push_back(p.first);
  }

  for (int i = -N; i <= N; ++i) {
    for (const int &u : adj[i]) {
      radj[u].push_back(i);
    }
  }

  for (int i = -N; i <= N; ++i) if (i != 0) dfs(i, order);
  swap(adj, radj);

  memset(uvisited, false, sizeof(uvisited));
  for (int i = -N; i <= N; ++i) {
    if (!visited[i] && i != 0) {
      vector<int> cc;
      dfs(i, cc);
      sort(cc.begin(), cc.end());
      for (auto u : cc) {
        if (binary_search(cc.begin(), cc.end(), -u)) {
          cout << "No Solution.\n";
          return 0;
        }
        component[u] = components.size();
      }
      components.push_back(cc);
    }
  }
  
  swap(adj, radj);
  cadj.resize(components.size());
  memset(uvisited, false, sizeof(uvisited));
  for (int i = -N; i <= N; ++i) if (!visited[i] && i != 0) cdfs(i);

  memset(uvisited, false, sizeof(uvisited));
  for (int i = 0; i < components.size(); ++i) if (!visited[i]) topsort(i);

  memset(uvisited, false, sizeof(uvisited));
  for (int i : tsort) {
    for (auto u : components[i]) {
      if (visited[abs(u)]) continue;
      visited[abs(u)] = true;
      answers[abs(u)] = u < 0;
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << "x" << i << ": " << boolalpha << answers[i] << '\n';
  }
}