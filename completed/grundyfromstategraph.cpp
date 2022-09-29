#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
vector<int> adj[MAX+1] = {
  {},
  {2, 4},
  {4, 6},
  {1, 4},
  {6},
  {4}
};
char vstate[MAX];
int state[MAX];
int N = 6;

bool toph(int s, vector<int> &path) {
  vstate[s] = 1;
  for (int u : adj[s]) {
    if (vstate[u] == 1) return false;
    if (vstate[u] != 2) if (!toph(u, path)) return false;
  }
  path.push_back(s);
  vstate[s] = 2;
  return true;
}

vector<int> tops() {
  vector<int> path;
  for (int i = 1; i <= N; ++i) {
    if (vstate[i] != 2) if (!toph(i, path)) {cout << "Not a valid state graph.\n"; exit(0);}
  }
  return path;
}

int mex(int s) {
  set<int> nums;
  for (int u : adj[s]) nums.insert(state[u]);
  if (nums.size() == 0 || *nums.begin() != 0) return 0;
  auto it1 = nums.begin(), it2 = it1; ++it2;
  while (it2 != nums.end() && *it2 - *it1 == 1) ++it1, ++it2;
  return *it1 + 1;
}

int main() {
  // topological sort the state graph - should always work because the game must end sooner or later (acyclic & directed)
  vector<int> order = tops();
  for (int u : order) state[u] = mex(u);
  copy(state+1, state+1+N, ostream_iterator<int>(cout, " "));
}