#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ul;

int main() {
  ul n;
  cin >> n;
  vector<pair<ul, ul>> f;
  for (ul x = 2; x*x <= n; ++x) {
    while (n % x == 0) {
      if (f.empty() || f.back().first != x) 
        f.push_back({x, 0});
      ++f.back().second;
      n /= x;
    }
  }
  if (n > 1) f.push_back({n, 1});

  ul total = 1;
  for (ul i = 0, p, a; i < f.size(); ++i) {
    tie(p, a) = f[i];
    total *= pow(p, a-1) * (p - 1);
  }

  cout << total;
}