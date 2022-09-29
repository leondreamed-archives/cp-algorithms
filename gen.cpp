#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

const int R = 500, C = 500;
int EX, EY;
vector<pair<int, int>> ops;

int main() {
  cout << R << " " << C << " " << R * C - 1 << '\n';
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);
  EX = rand() % C;
  EY = rand() % R;
  for (int y = 0; y < R; ++y) {
    for (int x = 0; x < C; ++x) {
      if (y == EY && x == EX) {cout << "1 "; continue;}
      ops.push_back({x, y});
      cout << "0 ";
    }
    cout << '\n';
  }

  shuffle(ops.begin(), ops.end(), default_random_engine(rand()));
  for (const pair<int, int> &p : ops)
    cout << p.first << " " << p.second << '\n';
}