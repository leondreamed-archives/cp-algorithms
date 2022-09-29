#include <bits/stdc++.h>
using namespace std;

int main() {
  uint64_t n;
  cin >> n;
  vector<pair<uint64_t, uint64_t>> f;
  for (uint64_t x = 2; x*x < n; ++x) {
    while (n % x == 0) {
      if (f.empty() || f.back().first != x) f.push_back({x, 0});
      ++f.back().second;
      n /= x;
    }
  }
  if (n > 1) f.push_back({n, 1});

  int nof = 1;
  for (const pair<uint64_t, uint64_t> &p : f) {
    nof *= p.second + 1;
  }

  cout << "Number of factors: " << nof << '\n';

  vector<uint64_t> factors;

  cout << "These factors are: \n";
  vector<uint64_t> inc(f.size(), 0);
  
  while (1) {
    uint64_t cur = 1;
    for (int p = 0; p < f.size(); ++p) cur *= pow(f[p].first, inc[p]);
    factors.push_back(cur);
    int i = 0;
    ++inc[i];
    while (i != f.size() && inc[i] > f[i].second)
      inc[i] = 0, ++inc[++i];
    if (i == f.size()) break;
  }

  sort(factors.begin(), factors.end());

  copy(factors.begin(), factors.end(), ostream_iterator<uint64_t>(cout, " "));
  cout << '\n';
}