#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> sieve(n+1);
  for (int x = 2; x*x <= n; ++x) {
    if (sieve[x]) continue;
    for (int i = x+x; i <= n; i += x) {
      sieve[i] = x;
    }
  }
  for (int x = 2; x <= n; ++x) {
    if (!sieve[x]) cout << x << ' ';
  }
  cout << '\n';
}