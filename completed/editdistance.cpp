#include <bits/stdc++.h>
using namespace std;

// dist[i][j] = edit dist from substring str1[0..i], str2[0..j]
vector<vector<int>> dist;

int main() {
  string str1, str2;
  cout << "Enter string #1:\n";
  getline(cin, str1);
  cout << "Enter string #2:\n";
  getline(cin, str2);
  dist.resize(str1.length()+1);
  int count = 0;
  for (auto &v : dist) {
    v.resize(str2.length()+1);
    v[0] = count++;
  }
  count = 0;
  for_each(dist[0].begin(), dist[0].end(), [&count](int &i){i = count++;});
  // dist(a, b) = min(dist(a-1, b)+1, dist(a, b-1)+1, dist(a-1, b-1)+cost(a, b));
  
  for (int i = 1; i <= str1.length(); ++i) {
    for (int j = 1; j <= str2.length(); ++j) {
      dist[i][j] = min(min(dist[i-1][j]+1, dist[i][j-1]+1),
      dist[i-1][j-1]+!(str1[i-1] == str2[j-1]));
    }
  }
  for (int i = 0; i <= str1.length(); ++i) {
    for (int j = 0; j <= str2.length(); ++j) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }

  cout << dist[str1.length()][str2.length()] << endl;
}