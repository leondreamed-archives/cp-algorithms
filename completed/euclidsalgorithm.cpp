#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

uint64_t gcd(uint64_t m, uint64_t n) {
  this_thread::sleep_for(milliseconds(10));
  if (n == 0) return m;
  return gcd(n, m%n);
}

int main() {
  uint64_t a, b;
  while (1) {
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
  }
}