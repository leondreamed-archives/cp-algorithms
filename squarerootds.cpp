#include <bits/stdc++.h>
using namespace std;

int N, S;
vector<int> blocks;
vector<int> numbers;

void update(int i, int v) {
  blocks[i/S] += v - numbers[i];
  numbers[i] = v;
}

int sum(int a, int b) {
  int s = 0, i = a;
  while (i <= b && i % S != 0) s += numbers[i++];
  while (i + S <= b) s += blocks[i/S], i += S;
  while (i <= b) s += numbers[i++];
  return s;
}

int main() {
  cin >> N;
  numbers.resize(N);
  S = sqrt(N);
  blocks.resize(ceil(sqrt(N)));
  for (int i = 0, b = -1; i < N; ++i) {
    if (i % S == 0) ++b;
    cin >> numbers[i];
    blocks[b] += numbers[i];
  }

  copy(blocks.begin(), blocks.end(), ostream_iterator<int>(cout, " ")); cout << '\n';
  copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " ")); cout << '\n';
}