#include <bits/stdc++.h>
using namespace std;

int m = 1000000000;
int modpow(int x, int n) {
  if (n == 0) return 1%m;
  long long u = modpow(x,n/2);
  u = (u*u)%m;
  if (n%2 == 1) u = (u*x)%m;
  return u;
}

int main() {
  int n;
  cin >> n;
  int ans = 18 * (1-modpow(10, ceil(n/2.0)) / -9);
  if (n == 0) cout << 1;
  else if (n == 1) cout << 9;
  else {
    if (n % 2 == 1) ans -= (9*modpow(10, n/2))%m;
    cout << ans % m;
  }
}