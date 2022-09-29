#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int64_t n = 2500;
int64_t subgrid[n][n];

bitset<n> rows[n];

void generate() {
  srand(time(0));
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = 0; j < n; ++j){
      subgrid[i][j] = rand() & 1;
    }
  }

  cerr << "Generation Finished\n";
}

void fastalgor() {
  auto t1 = high_resolution_clock::now();
  for (int64_t i = 0; i < n; ++i) {
    bitset<n> b;
    for (int64_t j = 0; j < n; ++j) {
      if (subgrid[i][j]) b.set(n-j-1);
    }
    rows[i] = move(b);
  }

  // Go through all possible pairs
  int64_t squares = 0;
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = i+1, count; j < n; ++j) {
      count = (rows[i] & rows[j]).count();
      squares += ((count - 1) * count) / 2;
    }
  }
  cout << squares << endl;

  auto t2 = high_resolution_clock::now();
  cout << duration_cast<milliseconds>(t2 - t1).count() << endl;
}

void slowalgor() {
  auto t1 = high_resolution_clock::now();
  // Go through all possible pairs
  int64_t squares = 0;
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = i+1, count; j < n; ++j) {
      count = 0;
      // Go through all columns and count black squares
      for (int64_t k = 0; k < n; ++k) {
        if (subgrid[i][k] && subgrid[j][k]) ++count;
      }
      squares += ((count - 1) * count) / 2;
    }
  }
  cout << squares << endl;
  auto t2 = high_resolution_clock::now();
  cout << duration_cast<nanoseconds>(t2 - t1).count() << endl;
}

int main() {
  generate();
  fastalgor(); 
}