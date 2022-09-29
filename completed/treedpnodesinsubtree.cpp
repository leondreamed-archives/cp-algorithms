#include <bits/stdc++.h>
using namespace std;

const int n = 6;
const int inf = 0x3f3f3f3f;
vector<int> adj[n+1] = {
  {},
  {2, 3, 4},
  {5, 6}
};

int dist[n+1];
bool ready[n+1];

int calc(int a) {
  if (ready[a]) return dist[a];
  int &ret = dist[a] = 1;
  for (int b : adj[a]) {
    ret += calc(b);
  }
  ready[a] = true;
  return ret;
}

int main() {
  calc(1);
  for (int i = 1; i <= n; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
}