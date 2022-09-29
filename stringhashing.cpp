#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int h[MAX];
int p[MAX];
const int A = 3, B = 97;

int calc(int a, int b) {
  return (h[b] - h[a-1] * p[b - a + 1]) % B;
}

int main() {
  string s;
  getline(cin, s);
  h[0] = s[0];
  p[0] = 1;
  for (int i = 1; i < s.length(); ++i) {
    h[i] = (h[i-1] * A + s[i]) % B;
    p[i] = (p[i-1] * A) % B;
  }

  cout << calc(0, s.length() - 1);
}