#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n+1] {
  {},
  {2, 3, 4},
  {5, 6}
};

int maxLength1[n+1];
int maxLength2[n+1];
int through[n+1];
int maxLengthP[n+1];
int maxLength[n+1];

void dfs1(int s, int e) {
  int &mx1 = maxLength1[s], &mx2 = maxLength2[s];
  mx1 = mx2 = 0;
  int res;
  for (int u : adj[s]) {
    if (u == e) continue;
    dfs1(u, s);
    res = maxLength1[u] + 1;
    if (res > mx1) mx2 = mx1, mx1 = res, through[s] = u;
    else if (res > mx2) mx2 = res;
  }
}

void dfs2(int s, int e) {
  int mx = (through[e] == s ? maxLength2[e] : maxLength1[e]);
  maxLengthP[s] = max(mx + 1, maxLengthP[e] + 1);
  maxLength[s] = max(maxLengthP[s], maxLength1[s]);
  for (int u : adj[s]) if (s != e) dfs2(u, s);
}

template <typename T>
void parr(T *p) {
  for (int i = 1; i <= n; ++i) {
    cout << *(p + i) << " ";
  }
  cout << endl;
}

int main() {
  maxLength[0] = maxLength1[0] = maxLength2[0] = maxLengthP[0] = through[0] = -1;
  dfs1(1, 0);
  dfs2(1, 0);

  cout << "maxLength1: "; parr(maxLength1);
  cout << "maxLength2: "; parr(maxLength2);
  cout << "through: "; parr(through);
  cout << "maxLengthP: "; parr(maxLengthP);
  cout << "maxLength: "; parr(maxLength);
}