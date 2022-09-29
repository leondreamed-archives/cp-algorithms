#include <bits/stdc++.h>
using namespace std;

const int n = 7;
array<vector<int>, n+1> adj = {
  vector<int>{},
  vector<int>{2, 4},
  vector<int>{1, 5},
  vector<int>{2, 7},
  vector<int>{},
  vector<int>{4},
  vector<int>{3, 5},
  vector<int>{6}
};
bool visited[n+1];

void dfs(int k, stack<int> &s) {
  visited[k] = true;
  for (auto &u : adj[k]) {
    if (!visited[u]) dfs(u, s);
  }
  s.push(k);
}

void dfs(int k, vector<int> &c) {
  visited[k] = true;
  for (auto &u : adj[k]) {
    if (!visited[u]) dfs(u, c);
  }
  c.push_back(k);
}

int main() {
  stack<int> s;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) dfs(i, s);
  }
  

  {
    array<vector<int>, n+1> radj;
    for (int i = 1; i <= n; ++i) {
      for (auto &e : adj[i]) {
        radj[e].push_back(i);
      }
    }
    adj = move(radj);
  }

  vector<vector<int>> components;
  vector<int> c;
  memset(visited, false, sizeof(visited));

  while (!s.empty()) {
    int i = s.top(); s.pop();
    if (visited[i]) continue;
    dfs(i, c);
    components.push_back(c);
    c.clear();
  }

  for_each(components.begin(), components.end(), [](vector<int> &v){copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout << endl;});
}