#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define uint uint64_t
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pii;
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}

vector<array<int, 3>> tree;

int sum_formula(int d, int x, int y) {
  int n = y-x;
  if (d == 0) return n+1;
  if (d == 1) return n*(n+1)/2;
  return 0;
}

int sum(int k, int x, int y) {
  int s = 0;
  for (int i = 0; i < 2; ++i) {
    s += tree[k][i] * sum_formula(i, x, y);
  }
  return s;
}

int update(int a, int b, int k, int x, int y, array<int, 2> poly) {
  if (b < x || a > y) return 0;
  int &s = tree[k][2];
  int os = s;
  if (x >= a && y <= b) {
    s -= sum(k, x, y);
    tree[k][0] += poly[0];
    tree[k][1] += poly[1];
    s += sum(k, x, y);
    return s - os;
  }
  int d = (x+y)/2;
  if (d >= a && d < b) {
    s += update(a, b, 2*k, x, d, poly);
    poly[0] += poly[1] * (d-a+1);
    s += update(a, b, 2*k+1, d+1, y, poly);
  } else if (d >= b) {
    s += update(a, b, 2*k, x, d, poly);
  } else if (d < a) {
    s += update(a, b, 2*k+1, d+1, y, poly);
  }
  return s - os;
}

int query(int a, int b, int k, int x, int y) {
  if (b < x || y < a) return 0;
  if (x >= a && y <= b) return tree[k][2];
  int d = (x+y)/2;
  if (tree[k][0] || tree[k][1]) {
    update(x, d, 2*k, x, d, {tree[k][0], tree[k][1]});
    update(d+1, y, 2*k+1, d+1, y, {tree[k][0] + tree[k][1] * (y-x+1)/2, tree[k][1]});
    tree[k][0] = tree[k][1] = 0;
  }
  return query(a, b, 2*k, x, d) + query(a, b, 2*k+1, d+1, y);
}

void printtree() {
  for_each(tree.begin()+1, tree.end(), [](const array<int, 3> &arr){
      copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, ","));
      cout << ' ';
  });
  cout << '\n';
}
#undef int
int main()
#define int int64_t
{
  int n, q;
  scan(n); scan(q);
  int s = 1 << (lg(n-1)+1);
  tree.resize(2*s);
  for (int i = 0; i < n; ++i) {
    int a;
    scan(a);
    update(i, i, 1, 0, s-1, {a, 0}); 
  }
  for (int t = 0; t < q; ++t) {
    int i, a, b;
    scan(i);
    scan(a);
    scan(b);
    --a, --b;
    if (i == 1) {
      update(a, b, 1, 0, s-1, {1, 1});
    } else {
      cout << query(a, b, 1, 0, s-1) << '\n';
    }
  }
}
