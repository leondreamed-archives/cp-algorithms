#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int tree[N];
int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void add(int k, int x) {
  while (k <= N) {
    tree[k] += x;
    k += k&-k;
  }
}

int sum(int k) {
  int s = 0;
  while (k > 0) {
    s += tree[k];
    k -= k&-k;
  }
  return s;
}

int main() {
  for (int i = 0; i < N; ++i) add(i+1, arr[i]);
  for (int i = 1; i <= N; ++i) cout << sum(i) << " "; cout << endl;
}