#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

constexpr inline int mylog2(int x) {
  return sizeof(int) * 8 - __builtin_clz(x) - 1;
}

const int N = 1 << 20;
const int U = 1 << 15;
const int S = static_cast<int>(mylog2(U)) + 1;
int succarr[N+1][S+1];
int succs[N+1];

int presucc(int x, int k) {
  int i = mylog2(k);
  if (succarr[x][i]) return succarr[x][i];
  else if (i == 0) return succarr[x][i] = succs[x];
  else return succarr[x][i] = presucc(presucc(x, k/2), k/2);
}

int succ(int x, int k) {
  if (k == 0) return x;
  else {
    int m = mylog2(k);
    return succ(succarr[x][m], k-(1<<m));
  }
}

int naivesucc(int x, int k) {
  for (int i = 0; i < k; ++i) {
    x = succs[x];
  }
  return x;
}

const int numq = 100000000;
pair<int, int> randq[numq];

int main() {
  srand(time(0));
  for (int i = 1; i < N; ++i) {
    succs[i] = rand() % N + 1;
  }

  {
    auto t1 = high_resolution_clock::now();
    for (int i = 1; i <= N; ++i) {
      presucc(i, U);
    }
    auto t2 = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(t2 - t1).count() << endl;
  }
  
  /*
  for (int i = 0; i < S; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << succarr[j][i] << " ";
    }
    cout << endl;
  }
  */
  
  for (int i = 0; i < numq; ++i) {
    randq[i] = make_pair(rand() % N + 1, rand() % U + 1);
  }
  { 
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < numq; ++i) {
      succ(randq[i].first, randq[i].second);
    }
    auto t2 = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(t2 - t1).count() << endl;
  }
  { 
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < numq; ++i) {
      naivesucc(randq[i].first, randq[i].second);
    }
    auto t2 = high_resolution_clock::now();
    cout << duration_cast<nanoseconds>(t2 - t1).count() << endl;
  }
  
}