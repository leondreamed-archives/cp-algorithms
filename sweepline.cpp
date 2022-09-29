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

struct Event {
  int start;
  bool isEntry;
  string name;
  Event(int s, bool i, string n) : start(s), isEntry(i), name(n) {}
  bool operator<(const Event &e) {
    return this->start < e.start;
  }
};
#undef int
int main()
#define int int64_t
{

/* 4
 * John 10 15
 * Maria 6 12
 * Peter 14 16
 * Lisa 5 13
 *
 * OUTPUT:
 * 3
 * John Lisa Maria
 */

    vector<Event> events;
 int n;
 scan(n);
 for (int i = 0; i < n; ++i) {
   string name; int s, e;
   cin >> name >> s >> e;
   events.push_back(Event(s, true, name));
   events.push_back(Event(e, false, name));
 }
  
 sort(events.begin(), events.end());
 int counter = 0, best = 0;
 for (Event &e : events) {
   if (e.isEntry) ++counter;
   else --counter;
   best = max(best, counter);
 }
 cout << best;
}
