#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ul;

int main() {
  ul n, on;
  cin >> n;
  on = n;
  vector<pair<ul, ul>> f;
  for (int x = 2; x*x <= n; ++x) {
    while (n % x == 0) {
      if (f.empty() || f.back().first != x) f.push_back({x, 0});
      ++f.back().second;
      n /= x;
    }
  }

  if (n > 1) f.push_back({n, 1});
  
  int nof = 1;
  for (int i = 0; i < f.size(); ++i) {
    nof *= f[i].second + 1;
  }

  cout << "The product of factors is: " << static_cast<ul>(pow(on, nof / 2)) << '\n';
}