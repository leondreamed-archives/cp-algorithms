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

char str[1000000];
#undef int
int main()
#define int long long
{

bool endq = false;
do {
  fgets(str, 1000000, stdin); 
  string line(str);
  string nline(line);
  int index = -1, c = 0;
  while ((index = line.find_first_of("\"", index + 1)) != (long long)string::npos) {
    nline.replace(index + c++, 1, endq ? "''" : "``"); 
    endq ^= 1;
  }
  if (feof(stdin)) nline.pop_back();
  cout << nline << '\n';
  if (feof(stdin)) break;
} while (true);
cout << '\n';

}
