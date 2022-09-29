#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int x = 5;
const int n = 100000;
vector<pair<int, int>> adj[n+1];

int dist[n+1];
const int inf = 0x3f3f3f3f;
bool visited[n+1];

void adjgen() {
  // e = number of edges on each node
  int rw, r1;
  const int e = 7800;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < e; ++j) {
      rw = (rand() % 10) + 5;
      r1 = (rand() % n) + 1;
      adj[i].push_back({r1, rw});
    }
  }
}

void spfa() {
  auto t1 = high_resolution_clock::now();
  for (int i = 1; i <= n; ++i) dist[i] = inf;
  dist[1] = 0;
  // starting node
  queue<int> nodes;
  nodes.push(1);
  int current;

  int iterations = 0;

  while (!nodes.empty()) {
    current = nodes.front(); nodes.pop();
    visited[current] = false;
    // looping through all paths of current node
    for (pair<int, int> &u : adj[current]) {
      ++iterations;
      if (dist[u.first] > dist[current] + u.second) {
        dist[u.first] = dist[current] + u.second;
        if (!visited[u.first]) {
          nodes.push(u.first);
          visited[u.first] = true;
        }
      }
    }
  }

  auto t2 = high_resolution_clock::now(); 
  cout << "SPFA: " << duration_cast<milliseconds>(t2-t1).count() << " with " << iterations << " iterations.\n";
  /* for (int i = 1; i <= n; ++i) cout << ((dist[i] == inf) ? -1 : dist[i]) << " ";
  cout << endl; */
}

void bellmanford() {
  auto t1 = high_resolution_clock::now();
  for (int i = 1; i <= n; ++i) dist[i] = inf;
  dist[1] = 0;
  int iterations = 0;

  for (int i = 1; i <= n; ++i) {
    for (auto &u : adj[i]) {
      ++iterations;
      if (dist[i] + u.second < dist[u.first]) {
        dist[u.first] = dist[i] + u.second;
      }
    }
  }
  auto t2 = high_resolution_clock::now();
  cout << "Bellman-Ford: " << duration_cast<milliseconds>(t2-t1).count() << " with " << iterations << " iterations.\n";
  /* for (int i = 1; i <= n; ++i) cout << ((dist[i] == inf) ? -1 : dist[i]) << " ";
  cout << endl; */
}

int main() {
  srand(time(0));
  adjgen();
  spfa();
  bellmanford();
}