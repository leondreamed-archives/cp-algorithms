#include <bits/stdc++.h>
using namespace std;

const int w = 7;
const int h = 5;
array<array<int, w+1>, h+1> arr;
array<array<int, w+1>, h+1> sum;

int main() {
  srand(time(0));
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      arr[i][j] = rand() % 10;
      sum[i][j] = arr[i][j];
      if (i > 0 && j > 0)
        sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
      else if (i > 0)
        sum[i][j] += sum[i-1][j];
      else if (j > 0)
        sum[i][j] += sum[i][j-1];
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }
  
  int x1, y1, x2, y2, total;
  while (cout << "Enter two one-indexed coordinates (coor 1 is top-left, coor 2 is bottom right, format: x1 y1 x2 y2): ",
  cin >> x1 >> y1 >> x2 >> y2) {
    total = sum[y2][x2] - sum[y2][x1-1] - sum[y1-1][x2] + sum[y1-1][x1-1];
    cout << "The sum of the elements contained in the rectangle with corners "
    << x1 << ", " << y1 << " and " << x2 << ", " << y2 << " is " << total << endl;
  }


}