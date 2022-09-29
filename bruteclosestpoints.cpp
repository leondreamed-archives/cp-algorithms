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

double brute() {
int n;
scan(n);
vector<pii> points;
for (int i = 0; i < n; ++i) {
  int a, b;
  cin >> a >> b;
  points.push_back({a, b});
}

pair<pii, pii> minp;
double d = inf;
for (int i = 0; i < n; ++i) {
  for (int j = i+1; j < n; ++j) {
    int x1 = points[i].first;
    int x2 = points[j].first;
    int y1 = points[i].second;
    int y2 = points[j].second;
    int a = abs(x1-x2), b = abs(y1-y2);
    double s = sqrt(a*a+b*b);
    if (s < d) {
      d = s;
      minp.first = points[i];
      minp.second = points[j];
    }
  }
}
// for_each(points.begin(), points.end(), [](pii p){cout << p << '\n';});
return d;
}
