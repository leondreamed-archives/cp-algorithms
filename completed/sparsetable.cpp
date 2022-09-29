#include <bits/stdc++.h>
using namespace std;

constexpr inline int mylog2(int a) {
  return sizeof(int) * 8 - __builtin_clz(a) - 1;
}

const int N = 9;
int values[N] = {2, 7, 4, 3, 2, 1, 6, 7, 5};
int sparse[N][mylog2(N)+1];

int minq(int a, int b) {
  int s = mylog2(b-a+1);
  int z = 1 << s;
  return min(sparse[a][s], sparse[b-z+1][s]);
}

int main() {
  for (int i = 0; i < N; ++i) sparse[i][0] = values[i];
  for (int s = 1; (1 << s) <= N; ++s)
    for (int i = 0; i + (1 << s) <= N; ++i)
      sparse[i][s] = min(sparse[i][s-1], sparse[i+(1<<(s-1))][s-1]);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= mylog2(N); ++j) cout << sparse[i][j] << " ";
    cout << endl;
  }

  cout << minq(6, 7) << endl;
}