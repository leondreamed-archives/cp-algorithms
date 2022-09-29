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

int cp(point p, point s1, point s2) {
  return (conj(p-s1)*(p-s2)).Y;
}
#undef int
int main()
#define int int64_t
{

  array<point, 4> p;
  for (int i = 0, a, b; i < 4; ++i) {
    scan(a); scan(b);
    p[i] = {a, b};
  }
  point a = p[0], b = p[1], c = p[2], d = p[3];
  if (cp(a, b, c) == 0 && cp(a, b, d) == 0) {
    if ((b.X < c.X && b.X < d.X && a.X < c.X && a.X < d.X) ||
        (b.X > c.X && b.X > d.X && a.X > c.X && a.X > d.X)) {
      cout << "No Point of Intersection.\n";
    } else {
      cout << "Lines overlap; infinite points of intersection.\n";
    }
  } else if (a == c || a == d || b == d || b == c) {
    cout << "A point of intersection exists at a vertex.\n";
  } else if (cp(a, b, c) * cp(a, b, d) <= 0 && cp(c, d, a) * cp(c, d, b) <= 0) {
    cout << "A point of intersection exists.\n";
  } else {
    cout << "No point of intersection.";
  }
} 
  
