#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int inf = 0x3f3f3f3f;
const int64_t linf = 0x3f3f3f3f;
typedef int64_t lint;
typedef pair<int, int> pii;
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}

vector<int> numbers;
vector<pair<int, int>> mul;
const int K = 1000000;
bitset<K> solve(int n) {
  bitset<K> ans;
  if (n == 0) return bitset<K>(1);
  else {
    for (int a = 0; a < n; ++a) {
      for (int t = 0; t <= mul[a].second; ++t) {
        ans |= solve(n-1) << t*mul[a].first;
      }
    }
  }
}
int main() {
  int N; // number of elements
  scan(N);
  for (int i = 0, a; i < N; ++i) {
    scan(a);
    numbers.push_back(a);
  }
  sort(numbers.begin(), numbers.end());

  solve(N);
}
