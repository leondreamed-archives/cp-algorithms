#include <bits/stdc++.h>
using namespace std;

const int N = 5, X = 10;
int weights[N] = {2, 3, 3, 5, 6};

pair<int, int> best[1<<N];

int main() {
  best[0] = {1, 0};
  // loop through all subsets of people
  for (int s = 1; s < (1<<N); ++s) {
    best[s] = {N+1, 0}; // worst case is N+1 rides that are needed
    for (int p = 0; p < N; ++p) {
      if (s&(1<<p)) {
        pair<int, int> option = best[s^(1<<p)]; // the best option if p was removed from the ride
        if (option.second + weights[p] > X) {
          ++option.first;
          option.second = weights[p];
        } else {
          option.second += weights[p];
        }
        best[s] = min(best[s], option);
      }
    }
  }

  cout << best[(1<<N)-1].first << endl;
}