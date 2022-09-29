#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int W = 4;
int values[N] = {2, 1, 4, 5, 3, 4, 1, 2};
int minima[N-W+1];
deque<pair<int, int>> window;

int main() {
  for (int i = 0; i < W; ++i) window.push_back({i, values[i]});
  for (int i = W-1; i < N; ++i) {
    if (!window.empty() && i - window.front().first >= W) window.pop_front();
    while (!window.empty() && window.back().second > values[i]) window.pop_back();
    window.push_back({i, values[i]});
    minima[i-W+1] = window.front().second;
  }
  copy(minima, minima+N-W+1, ostream_iterator<int>(cout, " ")); cout << endl;
}