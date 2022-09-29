#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int arr[N] = {2, 5, 6, 2, 7, 8, 1, 7, 4, 1};
int nse[N];
stack<int> s;

int main() {
  for (int i = 0; i < N; ++i) {
    while (!s.empty() && s.top() > arr[i]) s.pop();
    if (s.empty()) nse[i] = arr[i]; else nse[i] = s.top();
    s.push(arr[i]);
  }
  copy(nse, nse+N, ostream_iterator<int>(cout, " "));
}