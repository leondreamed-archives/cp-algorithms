#include <bits/stdc++.h>
using namespace std;

const int n = 5;

vector<pair<int, int>> adj[n+1] = {
  {},
  {{2, 5}, {3, 3}},
  {{1, 5}, {5, 2}, {4, 3}},
  {{1, 3}, {4, 1}},
  {{3, 1}, {5, 2}, {2, 3}},
  {{4, 2}, {2, 2}},
};
int dist[n+1];
const int inf = 0x3f3f3f3f;

int main() {
  for (int i = 1; i <= n; ++i) dist[i] = inf;
  dist[1] = 0;

  for (int i = 1; i <= n-1; ++i) {
    for (auto u : adj[i]) {
      dist[u.first] = min(dist[u.first], dist[i]+u.second);
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    if (dist[i] == inf) cout << -1;
    else cout << dist[i];
    cout << endl;
  }
}