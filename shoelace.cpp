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

int main() {
  int N;
  scan(N);
  int sum = 0;
  vector<pii> points;
  for (int i = 0, x, y; i < N; ++i) {
    scan(x); scan(y);
    points.push_back({x, y});
  }
  for (int i = 0; i < N; ++i) {
    sum += points[i].first * points[(i+1)%N].second - points[(i+1)%N].first * points[i].second;
  }
  cout << "Area: " << abs(sum)/2.0 << '\n';
}
