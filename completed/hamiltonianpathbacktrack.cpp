#include <bits/stdc++.h>
using namespace std;

const int N = 5;
vector<int> adj[N+1] = {
  {},
  {2, 4},
  {1, 3, 5},
  {2, 5},
  {1, 5},
  {2, 3, 4}
};

int mycount;
bool visited[N+1];

void dfs(int s, int c) {
  visited[s] = true;
  if (c == N) ++mycount;
  else {
    for (int u : adj[s]) {
      if (visited[u]) continue;
      dfs(u, c+1);
    }
  }
  visited[s] = false;
}

int main() {
  for (int i = 1; i <= N; ++i) dfs(i, 1);

  cout << mycount << endl;
}