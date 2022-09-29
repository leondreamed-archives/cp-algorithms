#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAX = 1000, inf = 0x3f3f3f3f;
int R, C;
int grid[MAX][MAX];
int dist[MAX][MAX];
int label[MAX][MAX];
map<int, vector<pair<int, int>>> letters;
queue<tuple<int, int, int>> q;

int pairs(int c) {
  int mindist = inf;
  pair<int, int> mp1, mp2;
  for (int i = 0; i < letters[c].size(); ++i) {
    for (int j = i+1; j < letters[c].size(); ++j) {
      pair<int, int> p = letters[c][i];
      pair<int, int> q = letters[c][j];
      int dist = abs(p.first - q.first) + abs(p.second - q.second);
      if (dist < mindist) {
        mp1 = p, mp2 = q;
        mindist = dist;
      }
    }
  }
  return mindist;
}

bool add(int x, int y, int l, int d, int ch) {
  if (x < 0 || x >= C || y < 0 || y >= R || label[y][x] == l) return false;
  if (label[y][x] != 0 && label[y][x] != l) return true;
  q.push({x, y, l}); label[y][x] = l; dist[y][x] = d+1;
  return false;
}

int bfs(int ch) {
  while (!q.empty()) q.pop();
  // simultaneously start a bfs search from every cell with letter c
  for (int i = 0; i < letters[ch].size(); ++i) {
    int x = letters[ch][i].first, y = letters[ch][i].second;
    q.push({x, y, i+1});
    dist[y][x] = 0;
    label[y][x] = i+1;
  }

  int x, y, l, d;
  while (!q.empty()) {
    tie(x, y, l) = q.front(); q.pop();
    d = dist[y][x];
    if (add(x+1, y, l, d, ch)) return d + dist[y][x+1] + 1;
    if (add(x-1, y, l, d, ch)) return d + dist[y][x-1] + 1;
    if (add(x, y+1, l, d, ch)) return d + dist[y+1][x] + 1;
    if (add(x, y-1, l, d, ch)) return d + dist[y-1][x] + 1;
  }

  return inf;
}

int main() {
  scan(R); scan(C);
  int sq = sqrt(R*C);
  for (int y = 0; y < R; ++y) {
    for (int x = 0; x < C; ++x) {
      scan(grid[y][x]);
      letters[grid[y][x]].push_back({x, y});
    }
  }

  int mindist = inf;
  for (const pair<int, vector<pair<int, int>>> &p : letters)
    if (p.second.size() < sq)
      mindist = min(mindist, pairs(p.first));
    else
      mindist = min(mindist, pairs(p.second));
  cout << mindist;
}