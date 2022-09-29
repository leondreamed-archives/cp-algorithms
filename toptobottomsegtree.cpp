#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int inf = 0x3f3f3f3f;
const int64_t linf = 0x3f3f3f3f;
typedef int64_t lint;
typedef uint64_t ulint;
typedef pair<int, int> pii;
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}

int M, N, Q;
vector<int> tree, lazy;

int sum(int a, int b, int k, int x, int y) {
  if (a > y || b < x) return 0; // [a..b] outside range
  if (x >= a && y <= b) return tree[k] + lazy[k] * (y-x+1); // [x..y] inside [a..b]
  // [a..b] {partially} inside [x..y]
  if (lazy[k]) {tree[k] += lazy[k] * (y-x+1); lazy[2*k] += lazy[k]; lazy[2*k+1] += lazy[k]; lazy[k] = 0;}
  int d = (x+y)/2; // finding middle
  return sum(a, b, 2*k, x, d) + sum(a, b, 2*k+1, d+1, y);
}

void add(int a, int b, int k, int x, int y, int v) {
  if (a > y || b < x) return; // if [x..y] is fully outside [a..b]
  if (x >= a && y <= b) {lazy[k] += v; return;} // if [x..y] is fully inside [a..b]
  // [x..y] is partially inside [a..b]
  int h; // size of intersection between [a..b] and [x..y]
  if (a >= x && b <= y) h = b-a+1; // [a..b] is fully inside [x..y]
  else if (b >= y && a >= x) h = y-a+1; // [x..y] intersects [a..b] from the left
  else if (x >= a && y >= b) h = b-x+1; // [x..y] intersects [a..b] from the right
  else {throw;}
  tree[k] += h*v;
  int d = (x+y)/2;
  add(a, b, 2*k, x, d, v); add(a, b, 2*k+1, d+1, y, v);
}

int main() {
  scan(M); scan(N); scan(Q);
  int S = (1 << (lg(N-1)+1));
  tree.resize(2*S);
  lazy.resize(2*S);

  for (int i = 0, v; i < N; ++i) {
    scan(v);
    add(i, i, 1, 0, S-1, v);
  }

  for (int i = 0, in, a, b, c; i < Q; ++i) {
    scan(in);
    if (in == 1) {
      scan(a); scan(b); scan(c);
      add(a-1, b-1, 1, 0, S-1, c);
    } else if (in == 2) {
      scan(a); scan(b);
      cout << sum(a-1, b-1, 1, 0, S-1) % M << '\n';
    } else if (in == 3) {
      copy(tree.begin(), tree.end(), ostream_iterator<int>(cout, " ")); cout << '\n';
      copy(lazy.begin(), lazy.end(), ostream_iterator<int>(cout, " ")); cout << '\n';
    }
  }
}
