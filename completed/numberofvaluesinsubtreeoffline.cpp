#include <bits/stdc++.h>
using namespace std;

const int N = 9;
vector<int> tree[N+1] = {
  {},
  {2, 3, 4, 5},
  {6},
  {},
  {7, 8, 9}
};

array<int, N+1> values = {0, 2, 3, 5, 3, 1, 4, 4, 3, 1};
array<map<int, int>, N+1> maps;

void dfs(int s) {
  ++maps[s][values[s]];
  for (int u : tree[s]) {
    dfs(u);
    for (const pair<int, int> &p : maps[u]) maps[s][p.first] += p.second;
  }
}

int main() {
  dfs(1);
  for (const map<int, int> &m : maps) {
    for_each(m.begin(), m.end(), [](const pair<int, int> &p){cout << p.first << "," << p.second << " ";}); cout << endl;
  }
}