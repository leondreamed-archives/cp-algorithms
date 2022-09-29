#include <bits/stdc++.h>
using namespace std;

constexpr inline int mylog2(int k) {
  return sizeof(int) * 8 - __builtin_clz(k) - 1;
}

struct Node {
  vector<int> children;
  int parent;
  Node(const initializer_list<int> &c, const int &p) : children(vector<int>(c)), parent(p) {}
};

const int N = 8;
Node nodes[N+1] = {
  Node({}, 0),
  Node({4, 5, 2}, 0),
  Node({6}, 1),
  Node({}, 4),
  Node({3, 7}, 1),
  Node({}, 1),
  Node({}, 2),
  Node({8}, 4),
  Node({}, 7)
};
int anc[N][mylog2(N)+1];

int preanc(int x, int k) {
  int &ret = anc[x][mylog2(k)];
  if (ret != -1) return ret;
  if (k == 1) return ret = nodes[x].parent;
  return ret = preanc(preanc(x, k/2), k/2);
}

int calcanc(int x, int k) {
  int m = k - (1 << mylog2(k));
  if (m == 0) {
    return anc[x][mylog2(k)];
  } else {
    return calcanc(anc[x][mylog2(m)], k-m);
  }
}

int main() {
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j <= mylog2(N); ++j)
      anc[i][j] = -1;

  for (int i = 1; i <= N; ++i) preanc(i, N);

  for (int j = 0; j <= mylog2(N); ++j) {
    for (int i = 1; i <= N; ++i)
      cout << anc[i][j] << " ";
    cout << '\n';
  }

  cout << calcanc(8, 2) << endl;
}