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
  const int HALF = 1000000;
  int n;
  int tree[HALF * 2 + 1];
struct Event {
  point start, end;
  bool vertical;
  bool isEntry;
  Event(point s, point e, bool v, bool i) : start(s), end(e), vertical(v), isEntry(i) {};
  bool operator<(const Event &e) {
    if (this->start.X == e.start.X) {
      if (!this->isEntry && !this->vertical) return false;
      else if (!e.isEntry && !e.vertical) return true;
      if (this->vertical) return false;
      else if (e.vertical) return true;
    }
    return this->start.X < e.start.X;
  }
};

void update(int x, int v) {
  while (x <= HALF * 2) {
    tree[x] += v;
    x+=x&-x;
  }
}

int query(int x) {
  int s = 0;
  while (x > 0) {
    s += tree[x];
    x -= x&-x;
  }
  return s;
}

#undef int
int main()
#define int int64_t
{
  vector<Event> events;
scan(n);
for (int i = 0; i < n; ++i) {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 += HALF; y1 += HALF; x2 += HALF; y2 += HALF;
  if (y1 > y2) swap(y1, y2);
  if (x1 > x2) swap(x1, x2);
  // entry horizontal/vertical
  events.push_back(Event(point{x1, y1}, point{x2, y2}, x1 == x2, true));
  if (x1 != x2) {
    // exit horizontal
    events.push_back(Event(point{x2, y2}, point{x2, y2}, false, false));
  }
}
sort(events.begin(), events.end());
int total = 0;
for (uint i = 0; i < events.size(); ++i) {
  Event &e = events[i];
  if (e.vertical) {
    total += query(e.end.Y) - query(e.start.Y-1);
  } else {
  if (e.isEntry) {
    update(e.start.Y, 1);
  } else {
    update(e.end.Y, -1);
  }
  }
}
cout << total;
}
