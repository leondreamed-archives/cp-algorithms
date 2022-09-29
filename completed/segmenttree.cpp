#include <bits/stdc++.h>
using namespace std;

constexpr inline int mylog2(int x) {
  return sizeof(int) * 8 - __builtin_clz(x) - 1;
}

const int N = 9;
int values[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
const int n = 1 << (mylog2(N-1) + 1);
int tree[2*n+1];

void add(int k, int x) {
  for (k += n, tree[k] += x, k /= 2; k > 0; k /= 2) tree[k] += x;
}

int sum(int a, int b) {
  a += n; b += n;
  int s = 0;
  if (a > b) swap(a, b);
  while (a <= b) {
    if (a % 2 == 1) s += tree[a++];
    if (b % 2 == 0) s += tree[b--];
    a /= 2, b /= 2;
  }
  return s;
}

int main() {
  for (int i = 0; i < N; ++i) add(i, values[i]);
  int a, b;
  while (cin >> a >> b) {
    cout << sum(a, b) << '\n';
  }
}