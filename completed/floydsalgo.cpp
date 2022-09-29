#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int succs[N] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 5};

inline int succ(int x) {
  return succs[x];
}

int main() {
  int a = 1, b = 1;
  do {
    a = succ(a);
    b = succ(succ(b));
  } while (a != b);
  a = 1;
  while (a != b) {
    a = succ(a);
    b = succ(b);
  }

  a = succ(a);
  int count = 1;
  while (a != b) {
    a = succ(a);
    ++count;
  }

  cout << count << endl;
}