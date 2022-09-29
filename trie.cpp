#include <bits/stdc++.h>
using namespace std;

const int N = 1000, A = 255;
int trie[N][A];

void add(string& s) {
  for (int i = 0; i < s.length(); ++i) {
    trie[i][s[i]] = i+1;
  }
}

int main() {
  for (;;) {
    string s;
    getline(cin, s);
    add(s);
  }
}