#include <bits/stdc++.h>
using namespace std;

const int N = 21;
int64_t possible[1 << (N+1)][N+1];
bool adj[N+1][N+1];

void addedge(int a, int b) {
  adj[a][b] = true;
  adj[b][a] = true;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = true;
  }
  
  for (int i = 1; i <= n; ++i) {
    possible[1<<i][i] = 1;
    for (int j = 1; j <= n; ++j) {
      possible[(1<<i)|(1<<j)][j] = adj[i][j];
      possible[(1<<i)|(1<<j)][i] = adj[j][i];
    }
  }

  for (int s = 1; s < (1 << (n+1)); ++s) {
    for (int e = 1; e <= n; ++e) {
      // if s doesn't contain node e
      if (!(s&(1<<e))) {possible[s][e] = 0; continue;}
      for (int i = 1; i <= N; ++i) {
        if (s&(1<<i) && adj[i][e] && (s^(1<<i)) != (1 << e)) {
          possible[s][e] += possible[s^(1<<e)][i];
        }
      }
    }
  }
  /*
  for (int e = 1; e <= n; ++e) {
    for (int s = 1; s < (1 << (N+1)); ++s) cout << possible[s][e] << " ";
    cout << endl;
  }
  */

  int64_t total = 0;
  for (int i = 1; i <= n; ++i) {total += possible[((1<<(n+1))-1)^1][i];}
  cout << total << endl;

  
}
