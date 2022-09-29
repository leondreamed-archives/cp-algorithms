#include <bits/stdc++.h>
using namespace std;

string s = "acbacdacbacbacda";
int main() {
  vector<int> z(s.length());
  int x = 0, y = 0;
  for (int k = 1; k <= s.length(); ++k) {
    // y-k+1 is there to ensure that it doesn't exceed the y of the border
    // z[k-x] represents the prefix of the string matching the same position as the current box
    // note: k will always be at least as great as x
    z[k] = max(0, min(z[k-x], y-k+1)); 
    while (z[k]+k < s.length() && s[z[k]] == s[z[k]+k]) {
      x = k; y = k+z[k]; ++z[k];
    }
  }
  copy(z.begin(), z.end(), ostream_iterator<int>(cout, " "));
}