#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 10000000;
vector<int> adj[MAX+1];
bool state[MAX+1];
int sq[MAX+1];

void processpf(int s) {
  int n = s;
  vector<pair<int, int>> f;
  for (int x = 2; sq[x] <= s; ++x) {
    while (n % x == 0) {
      if (f.empty() || f.back().first != x) f.push_back({x, 0});
      ++f.back().second;
      n /= x;
    }
  }
  if (n > 1) f.push_back({n, 1});

  int nf = f.size();
  vector<int> factors;
  vector<int> idx(nf, 0);

  for (;;) {
    int i = 0, cf = 1;
    for (int j = 0; j < nf; ++j) cf *= pow(f[j].first, idx[j]);
    factors.push_back(cf);
    ++idx[i];
    while (idx[i] > f[i].second) {idx[i] = 0; if (++i == nf) goto out; else ++idx[i];}
  }
  
  out:;
  factors.pop_back();
  for (int u : factors) adj[s].push_back(s-u);
}

void process(int s) {
  for (int i = 1; i <= s/2; ++i) {
    if (s % i == 0) adj[s].push_back(s-i);
  }
}

bool calc(int s) {
  for (int u : adj[s]) {
    if (state[u] == false) return true;
  }
  return false;
}

int main() {
  cin >> N;
  state[1] = false;
  for (int i = 0; i <= N; ++i) sq[i] = i*i;
  for (int i = 2; i <= N; ++i) processpf(i);
  for (int i = 2; i <= N; ++i) state[i] = calc(i);
  // copy(state+1, state+1+N, ostream_iterator<int>(cout, " "));
}