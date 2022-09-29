#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> adj[N+1];
vector<int> rev[N+1];
vector<bool> used[N+1];
array<int, N+1> idx;
list<int> path;

void addpath(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
  rev[a].push_back(adj[b].size()-1);
  rev[b].push_back(adj[a].size()-1);
}

int main() {
  // getting input
  int a, b;
  while (cin >> a >> b) {
    addpath(a, b);
  }
  for (int i = 1; i <= N; ++i) used[i].resize(adj[i].size());

  int oc = 0, oi1 = 0, oi2 = 0;
  // checking if Eulerian path exists
  for (int i = 1; i <= N; ++i) {
    if (adj[i].size()&1) {
      if (++oc > 2) break;
      oi2 = oi1; oi1 = i;
    }
  }

  

  if (oc == 2) {
    addpath(oi1, oi2);
    used[oi1].push_back(false);
    used[oi2].push_back(false);
  } else if (oc != 0) {
    cout << "Graph does not contain a Eulerian path.\n"; return 0;
  }

  path.push_back(max(oi1, 1));

  for (auto it = path.begin(); it != path.end(); ++it) {
    int startN = *it;
    int cur = startN;
    auto ins = it; ++ins;

    do {
      int &curI = idx[cur];
      // finding next unused node
      while (curI != adj[cur].size() && used[cur][curI]) ++curI;
      if (curI == adj[cur].size()) break;
      used[cur][curI] = true;
      used[adj[cur][curI]][rev[cur][curI]] = true;
      cur = adj[cur][curI];
      path.insert(ins, cur);
      ++curI;
    } while (cur != startN);
  }

  // if added extra path find this path and remove it
  if (oc == 2) { 
    auto it1 = path.begin(), it2 = path.begin(); ++it2;
    while (it2 != path.end() && (*it1 != oi1 || *it2 != oi2)) ++it1, ++it2;
    if (it2 == path.end()) {cout << "a bug!\n"; return 0;}
    path.pop_back();
    rotate(path.begin(), it2, path.end());
  }

  copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}