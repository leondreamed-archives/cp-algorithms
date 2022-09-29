#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<int> tree[N+1] = {
  {},
  {2, 3, 4},
  {5, 6},
  {},
  {7},
  {},
  {8}
};
vector<int> ni;
vector<int> dep;
array<int, N+1> pos;

const int inf = 0x3f3f3f3f;

void dfs(int s, int d) {
  pos[s] = ni.size();
  ni.push_back(s);
  dep.push_back(d);
  for (int u : tree[s]) {
    dfs(u, d+1);
    ni.push_back(s);
    dep.push_back(d);
  }
}

constexpr inline int mylog2(int s) {
  return sizeof(int) * 8 - __builtin_clz(s) - 1;
}

pair<int, int> sparse[2*N-1][mylog2(2*N-1)+1];

pair<int, int> cmin(int a, int b) {
  int i = mylog2(b-a+1);
  pair<int, int> &ret = sparse[a][i];
  if (ret.first != inf) return ret;
  if (i == 0) return ret = make_pair(dep[a], ni[a]);
  int w = (b-a+1)/2;
  return ret = min(cmin(a, a+w-1), cmin(a+w, b));
}

pair<int, int> minq(int a, int b) {
  if (b < a) swap(a, b);
  int k = mylog2(b-a+1);
  return min(sparse[a][k], sparse[b-(1<<k)+1][k]);
}

int main() {
  memset(sparse, inf, sizeof(sparse));
  dfs(1, 1);
  copy(dep.begin(), dep.end(), ostream_iterator<int>(cout, " "));
  cout << '\n';
  for (int i = 0; i < 2*N-1; ++i) {
    for (int j = 0; i + (1 << j) / 2 < 2*N-1; ++j) {
      cmin(i, i+(1 << j)/2);
    }
  }

  cout << minq(pos[6], pos[3]).second;
}