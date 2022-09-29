#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define double long double
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef pair<double, double> pdd;
typedef complex<int> point;
typedef complex<double> fpoint;
#define X real()
#define Y imag()
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}
ostream& operator<<(ostream &output, const pii &p) {cout << '(' << p.first << "," << p.second << ')';return output;}
ostream& operator<<(ostream &output, const pdd &p) {cout << '(' << p.first << "," << p.second << ')';return output;}
template <typename T>constexpr const inline T& _max(const T& x, const T& y) {return x<y?y:x;}
template <typename T>constexpr const inline T& _min(const T& x, const T& y) {return x<y?x:y;}
template <typename T, typename ...S>constexpr const inline T& _max(const T& m, const S&...s) {return _max(m, _max(s...));}
template <typename T, typename ...S>constexpr const inline T& _min(const T& m, const S&...s) {return _min(m, _min(s...));}
#define max(...) _max(__VA_ARGS__)
#define min(...) _min(__VA_ARGS__)

int find_cycle_length(int n) {
  int l = 0;
  while (++l, n != 1) {
    if (n&1) n = 3*n + 1;
    else n = n/2;
  }
  return l;
}

#undef int
int main()
#define int long long
{

int a, b;
while (scanf("%lld%lld\n", &a, &b) == 2) {
  int m = 0;
  for (int i = min(a, b); i <= max(a, b); ++i) {
    m = max(m, find_cycle_length(i));
  }
  printf("%lld %lld %lld\n", a, b, m);
}

}
