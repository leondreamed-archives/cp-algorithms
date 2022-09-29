#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define uint uint64_t
#define double long double
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pii;
typedef complex<int> point;
typedef complex<double> fpoint;
#define X real()
#define Y imag()
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}

#undef int
int main()
#define int int64_t
{

int N;
scan(N);
vector<point> points;
for (int i = 0, a, b; i < N; ++i) {
  scan(a); scan(b);
  points.push_back({a, b}); 
}
int area = 0;
for (int i = 0; i < N; ++i) {
  int j = (i+1)%N;
  area += points[i].X * points[j].Y - points[j].X * points[i].Y;
}
cout << abs(area / 2.0);
}
