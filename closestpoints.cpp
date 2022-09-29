#include <bits/stdc++.h>
using namespace std::chrono;
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

int n;
vector<pii> points;

int brute_time;
int opt_time;

double brute() {

auto t1 = high_resolution_clock::now();
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
auto t2 = high_resolution_clock::now();
brute_time += duration_cast<nanoseconds>(t2-t1).count();

return d;
}

double opt() {
  auto t1 = high_resolution_clock::now();
  if (distance(points.begin(), unique(points.begin(), points.end())) != n) return 0;
  set<pii> active(points.begin()+1, points.end());
  pair<pii, pii> minp;
  double d = inf;
  for (uint i = 0; i < points.size(); ++i) {
    int x = points[i].first, y = points[i].second;
    for (auto it = active.begin(); it != active.end();) {
      if (it->first > x && (it->second < y-d || it->second > y+d || it->first < x-d) || (it->first == x && it->second == y)) {
        it = active.erase(it);
      } else {
        int a = abs(it->first-x), b = abs(it->second-y);
        double s = sqrt(a*a+b*b);
        if (s < d) {
          minp = {points[i], *it};
          d = s;
        }
        ++it;
      }
    }
    active.insert(points[i]);
  }
  auto t2 = high_resolution_clock::now();
  opt_time += duration_cast<nanoseconds>(t2-t1).count();

return d;
}

#undef int
int main()
#define int long long
{
  srand(time(0));
  const int MAX = 1000000;
  const int MAXX = 1000000000;
  const int MAXY = 1000000000;
  const int NUM_CASES = 1;
  for (int t = 1; t <= NUM_CASES; ++t) {
    n = rand() % MAX + 1;
    points.clear();
    for (int i = 0; i < n; ++i) {
      points.push_back({rand() % MAXX * (rand() % 2 ? -1 : 1), rand() % MAXY * (rand() % 2 ? -1 : 1)});
    }
    sort(points.begin(), points.end(), [](pii p1, pii p2){if (p1.second == p2.second) return p1.first < p2.first; return p1.second < p2.second;});
  }

  opt();
  cout << "Opt took\t" << opt_time/1000000  <<" milliseconds in total.\n";
}
