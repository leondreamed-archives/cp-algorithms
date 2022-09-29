#include <bits/stdc++.h>
using namespace std;

const int n = 7;
int seq[n] = {1, 2, 5, 1, 4, 7, 10};
valarray<int> length(1, n);

int main() {
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (seq[i] < seq[j]) length[j] = max(length[j], length[i]+1);
    }
  }
  cout << length.max() << endl;
}