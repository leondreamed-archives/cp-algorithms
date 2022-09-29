#include <bits/stdc++.h>
using namespace std;

const int n = 7;
vector<int> adj[n+1] = {
  {},
  {2, 3, 4},
  {5, 6},
  {},
  {7},
};

int toLeaf[n+1];
int maxLength[n+1];

void dfs(int s, int p) {
  int max1 = -1;
  int max2 = -1;
  for (auto u : adj[s]) {
    if (u != p) {
      dfs(u, s);
      if (toLeaf[u] + 1 > toLeaf[s]) {
        toLeaf[s] = toLeaf[u] + 1;
      }
      if (toLeaf[u] > max1) {
        max2 = max1;
        max1 = toLeaf[u];
      }
        
      else if (toLeaf[u] > max2)
        max2 = toLeaf[u];
    }
  }

  maxLength[s] = max1 + max2 + 2;
}

int main() {
  dfs(1, 0);
  int diam = 0;
  for (auto i : maxLength) {
    if (i > diam)
      diam = i;
    cout << i << " ";
  }
  cout << endl;
  cout << diam << endl;
}