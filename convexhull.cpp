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

int cp(const point &p1, const point &p2, const point &s) {
  return cp(p1-s, p2-s);
}

#undef int
int main()
#define int long long
{
vector<point> points;
int n;
scan(n);
for (int i = 0; i < n; ++i) {
  int a, b;
  cin >> a >> b;
  points.push_back({a, b});
}
sort(points.begin(), points.end(), [](const point &p1, const point &p2){
    if (p1.X == p2.X) return p1.Y < p2.Y; return p1.X < p2.X;
    });

vector<point> convex_hull;
list<point> segments;
for (int t = 0; t < 2; ++t) {
segments.push_back(points[0]);
for (uint i = 1; i < points.size(); ++i) {
  while (segments.size() > 1) {
    auto pit = segments.end(); --pit; --pit;
    // if it turns left
    if (t == 0 && cp(*pit, segments.back(), points[i]) > 0) segments.pop_back();
    else if (t == 1 && cp(*pit, segments.back(), points[i]) < 0) segments.pop_back();
    else break;
  } 
  segments.push_back(points[i]); 
}
if (t == 0) convex_hull.insert(convex_hull.end(), segments.begin(), segments.end());
else if (t == 1) {
  segments.pop_back();
  convex_hull.insert(convex_hull.end(), segments.rbegin(), segments.rend());
}
segments.clear();
}

copy(convex_hull.begin(), convex_hull.end(), ostream_iterator<point>(cout, " "));
}
