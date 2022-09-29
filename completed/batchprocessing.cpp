#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
using namespace std::chrono;

const int64_t MAX = 1000, inf = 0x3f3f3f3f;
int64_t opcount;
int64_t R, C, Q;
bool ogrid[MAX][MAX];
bool grid[MAX][MAX];
int64_t dist[MAX][MAX];
bool visited[MAX][MAX];

queue<tuple<int64_t, int64_t, int64_t>> q;
vector<pair<int64_t, int64_t>> totalpainted;

void add(int64_t x, int64_t y, int64_t d) {
  if (x < 0 || x >= C || y < 0 || y >= R || visited[y][x]) return;
  q.push({x, y, d+1}); visited[y][x] = true; dist[y][x] = d+1;
}

void printgrid() {
  for (int64_t y = 0; y < R; ++y) {
    for (int64_t x = 0; x < C; ++x) {
      cout << grid[y][x] << ' ';
    }
    cout << '\n';
  }
}

void printvisited() {
  for (int64_t y = 0; y < R; ++y) {
    for (int64_t x = 0; x < C; ++x) {
      cout << visited[y][x] << ' ';
    }
    cout << '\n';
  }
}

void bfs() {
  while (!q.empty()) q.pop();
  // simultaneous bfs from each black square (guaranteed O(n))
  for (int64_t i = 0; i < totalpainted.size(); ++i) {
    ++opcount;
    q.push({totalpainted[i].first, totalpainted[i].second, 0});
    visited[totalpainted[i].second][totalpainted[i].first] = true;
    dist[totalpainted[i].second][totalpainted[i].first] = 0;
  }

  int64_t x, y, d;
  while (!q.empty()) {
    opcount += 4;
    tie(x, y, d) = q.front(); q.pop();
    add(x+1, y, d);
    add(x, y+1, d);
    add(x-1, y, d);
    add(x, y-1, d);
  }
}

vector<pair<int64_t, int64_t>> opainted;
vector<pair<int64_t, int64_t>> painted;
int64_t listkeep(int64_t x, int64_t y) {
  int64_t mindist = inf;
  for (const pair<int64_t, int64_t> &p : painted) {
    ++opcount;
    mindist = min(mindist, abs(x - p.first) + abs(y - p.second));
  }
  painted.push_back({x, y});
  grid[y][x] = true;
  return mindist;
}

vector<vector<pair<int64_t, int64_t>>> batches;
vector<int64_t> minima1;
vector<int64_t> minima2;

void resetgrid() {
  for (int64_t y = 0; y < R; ++y) {
    for (int64_t x = 0; x < C; ++x) {
      grid[y][x] = ogrid[y][x];
    }
  }
}

int main() {
  scan(R); scan(C); scan(Q);
  int64_t sq = sqrt(R*C);

  for (int64_t y = 0; y < R; ++y) {
    for (int64_t x = 0, i; x < C; ++x) {
      scan(i); if (i) {
        opainted.push_back({x, y});
        ogrid[y][x] = true;
      }
    }
  }

  totalpainted = painted = opainted;
  resetgrid();

  pair<int64_t, int64_t> cp;
  for (int64_t i = 0; i < Q; ++i) {
    if (i % sq == 0) batches.push_back(vector<pair<int64_t, int64_t>>());
    scan(cp.first); scan(cp.second);
    batches.back().push_back(cp);
  }

  vector<int64_t> cbatch;
  {
  auto t1 = high_resolution_clock::now();
    // looping through O(sqrt(n)) batches
    for (int64_t b = 0; b < batches.size(); ++b) {
      for (int64_t i = 0; i < R; ++i) memset(visited[i], false, sizeof(visited[0])*C);
      cbatch.resize(batches[b].size());
      bfs();
      for (int64_t p = 0; p < batches[b].size(); ++p) {
        cbatch[p] = dist[batches[b][p].second][batches[b][p].first];
      }
      // calling listkeep (O(n) time) on each point
      for (int64_t p = 0; p < batches[b].size(); ++p)
        cbatch[p] = min(cbatch[p], listkeep(batches[b][p].first, batches[b][p].second));
      copy(cbatch.begin(), cbatch.end(), back_inserter(minima1));
      copy(painted.begin(), painted.end(), back_inserter(totalpainted));
      painted.clear();
    }
    auto t2 = high_resolution_clock::now();
    cerr << "Batched implementation: ";
    cerr << duration_cast<milliseconds>(t2 - t1).count() << '\n';
    cerr << "Opcount: " << opcount << '\n';
  }

  painted = opainted;
  resetgrid();
  opcount = 0;

  {
    auto t1 = high_resolution_clock::now();
    for (int64_t b = 0; b < batches.size(); ++b) {
      cbatch.resize(batches[b].size());
      for (int64_t p = 0; p < batches[b].size(); ++p)
        cbatch[p] = listkeep(batches[b][p].first, batches[b][p].second);
      copy(cbatch.begin(), cbatch.end(), back_inserter(minima2));
    }
    auto t2 = high_resolution_clock::now();
    cerr << "Naive implementation: ";
    cerr << duration_cast<milliseconds>(t2 - t1).count() << '\n';
    cerr << "Opcount: " << opcount << '\n';
  }

  // copy(minima1.begin(), minima1.end(), ostream_iterator<int64_t>(cout, " ")); cout << '\n';
  // copy(minima2.begin(), minima2.end(), ostream_iterator<int64_t>(cout, " ")); cout << '\n';
  assert(minima1 == minima2);
}