#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
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
ostream& operator<<(ostream &output, const pii &pii) {
  cout << '(' << pii.first << "," << pii.second << ')';
  return output;
}

int cp(const point &p1, const point &p2) {
  return (conj(p1)*p2).Y;
}

int cp(const point &_p1, const point &_p2, const point &s) {
  point p1 = _p1, p2 = _p2;
  if (p1.Y > p2.Y) swap(p1, p2);
  else if (p1.Y == p2.Y && p1.X > p2.X) swap(p1, p2);
  return cp(s-p1, s-p2);
}
int n;
vector<point> polygon;

/*
 * TODO: Fix on flat lines, e.g.:
 * 
 * 4
 * 0 1
 * 1 1
 * 2 2
 * 1 0
 * 1
 * -1 1
 *
 */

bool is_inside(const point &s) {
  bool inside = false;
  for (int i = 0; i < n; ++i) {
    // point p3 helps identify the type of vertex
    point p1 = polygon[i], p2 = polygon[(i+1)%n], p3 = polygon[(i+2)%n];
    // parallel to line either has no effect or gurantees insidity
    if (p1.Y == p2.Y && p2.Y == s.Y) {
      if (s.X >= min(p1.X, p2.X) && s.X <= max(p1.X, p2.X)) return true;
      else continue;
    }
    // checking for the intersection of a vertex
    if (s.Y == p2.Y && s.X < p2.X) {
      if (min(p1.Y, p3.Y) < p2.Y && max(p1.Y, p3.Y) > p2.Y) inside ^= 1;
      continue;
    }
    // checking if point is on a line
    if (cp(p1, p2, s) == 0 && (s.X <= max(p1.X, p2.X) && s.X >= min(p1.X, p2.X) &&
          s.Y >= min(p1.Y, p2.Y) && s.Y <= max(p1.Y, p2.Y))) return true;
    // checking for intersection
    if ((s.Y > min(p1.Y, p2.Y) && s.Y < max(p1.Y, p2.Y)) && cp(p1, p2, s) > 0) {
      inside ^= 1;
    }
  }
  return inside;
}

#undef int
int main()
#define int long long
{

  scan(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    polygon.push_back({a, b});
  }
  int q;
  scan(q);
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << point{a, b} << " " << boolalpha << is_inside({a, b}) << '\n';
  }
}
