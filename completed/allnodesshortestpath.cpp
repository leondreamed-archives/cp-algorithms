#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int maxLength1[N+1];
int maxLength2[N+1];
int maxLengthP[N+1];
int maxLength[N+1];
int through[N+1];
vector<int> adj[N+1] = {
  {},
  {2, 3, 4},
  {5, 6},
  {},
  {7},
  {},
  {8}
};

void dfs(int s) {
  maxLength1[s] = maxLength2[s] = 0;
  for (int u : adj[s]) {
    dfs(u);
    int maxu = maxLength1[u] + 1;
    if (maxu > maxLength1[s]) {
      maxLength2[s] = maxLength1[s];
      maxLength1[s] = maxu;
      through[s] = u;
    } else if (maxu > maxLength2[s]) { 
      maxLength2[s] = maxu;
    }
  }
}

void dfs2(int s, int e) {
  int mx = (through[e] == s ? maxLength2[e] : maxLength1[e]);
  maxLengthP[s] = max(mx, maxLengthP[e]) + 1;
  maxLength[s] = max(maxLengthP[s], maxLength1[s]);
  for (int u : adj[s]) dfs2(u, s);
}

int main() {
  maxLength1[0] = maxLengthP[0] = -1;
  dfs(1);
  dfs2(1, 0);
  copy(maxLength1+1, maxLength1+N+1, ostream_iterator<int>(cout, " ")); cout << endl;
  copy(maxLength2+1, maxLength2+N+1, ostream_iterator<int>(cout, " ")); cout << endl;
  copy(through+1, through+N+1, ostream_iterator<int>(cout, " ")); cout << endl;
  copy(maxLengthP+1, maxLengthP+N+1, ostream_iterator<int>(cout, " ")); cout << endl;
  copy(maxLength+1, maxLength+N+1, ostream_iterator<int>(cout, " ")); cout << endl;
}