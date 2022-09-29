#include <bits/stdc++.h>
using namespace std;

uint64_t n;

int main() {
  cin >> n;
  vector<uint64_t> factors;
  for (uint64_t x = 2; x*x <= n; ++x) {
    while (n % x == 0) {
      factors.push_back(x);
      n /= x;
      if (n == 1) break;
    }
  }
  if (n != 1) factors.push_back(n);
  copy(factors.begin(), factors.end(), ostream_iterator<uint64_t>(cout, " ")); cout << '\n';
}