#include <bits/stdc++.h>
using namespace std;

const int n = 6;

vector<pair<int, int>> adj[n+1] = {
  {},
  {{2, 3}, {5, 5}},
  {{1, 3}, {3, 5}, {5, 6}},
  {{2, 5}, {6, 3}, {4, 9}},
  {{3, 9}, {6, 7}},
  {{1, 5}, {2, 6}, {6, 2}},
  {{3, 3}, {5, 2}, {4, 7}}
};

bool added[n+1];
int link[n+1];

int main() {
  // weight, from, to
  priority_queue<tuple<int, int, int>> q;
  q.push({0, 1, 1});

  int weight = 0;

  while (!q.empty()) {
    int w, f, t;
    tie(w, f, t) = q.top(); q.pop();
    if (added[t]) continue;
    added[t] = true;
    link[t] = f;
    for (pair<int, int> &p : adj[t]) {
      q.push(make_tuple(-p.second, t, p.first));
    }
    weight += -w;
  }

  cout << weight << endl;
}