#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int inf = 0x3f3f3f3f;
const int64_t linf = 0x3f3f3f3f;
typedef int64_t lint;
typedef pair<int, int> pii;
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - __builtin_clz(x) - is_signed<T>::value;
}

int V = 10000, E = 20000;
vector<int> numbers;
vector<pair<int, int>> poss;

int main() {
  cout << V << " " << E << '\n';
  for (int i = 1; i <= V; ++i) numbers.push_back(i);
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));
  vector<int> firsthalf(numbers.begin(), numbers.begin()+V/2),
  secondhalf(numbers.begin()+V/2, numbers.end());
  for (int i = 0; i < V/2; ++i) {
    for (int j = 0; j < V/2; ++j) {
      poss.push_back({firsthalf[i], secondhalf[j]});
    }
  }

  shuffle(poss.begin(), poss.end(), default_random_engine(seed));
  for (int i = 0; i < E; ++i) {
    cout << poss[i].first << " " << poss[i].second << '\n';
  }
}