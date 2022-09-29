#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<int> adj[N+1] = {
  {},
  {2, 3, 4},
  {5, 6},
  {},
  {7},
  {},
  {8}
};

vector<int> queries[N+1] = {
  {},
  {8},
  {5, 8, 6},
  {7, 4},
  {7, 3},
  {8, 2},
  {2, 7},
  {4, 3, 6},
  {5, 2, 1}
};

vector<int> answers[N+1];

int ancestor[N+1];
bool visited[N+1];
int siz[N+1];
int link[N+1];

int find(int x) {
  while (x != link[x]) x = link[x];
  return x;
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (b > a) swap(a, b);
  siz[a] += siz[b];
  link[b] = a;
}

void dfs(int s) {
  visited[s] = true;
  ancestor[s] = s;

  for (int u : adj[s]) {
    dfs(u);
    unite(u, s);
    // in case unite changed representative of set
    ancestor[find(s)] = s;
  }

  for (int i = 0; i < queries[s].size(); ++i) {
    if (visited[queries[s][i]]) answers[s][i] = ancestor[find(queries[s][i])];
  }

}

int main() {
  for (int i = 1; i <= N; ++i) {link[i] = i; siz[i] = 1;}
  for (int i = 1; i <= N; ++i) answers[i].resize(queries[i].size());
  dfs(1);
  for (int i = 1; i <= N; ++i) {
    cout << i << ": ";
    copy(answers[i].begin(), answers[i].end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
}