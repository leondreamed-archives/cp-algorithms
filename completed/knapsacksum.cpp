#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const int W = 12;
int weights[N] = {1, 3, 3, 5};
bool possible[W+1];

int main() {
  possible[0] = true;
  for (int i = 0; i < N; ++i) {
    for (int j = W; j >= 0; --j) {
      if (possible[j]) possible[j+weights[i]] = true;
    }
  }
  for (bool b : possible) cout << b;
  cout << endl;
}