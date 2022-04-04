#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  scanf("%d", &n);
  vector<int> data(n), tmp;
  vector<vector<int>> rem(4, vector<int>(4, 0));
  for (auto &i : data)
    scanf("%d", &i);
  tmp = data;
  sort(tmp.begin(), tmp.end());
  for (int c = 0; c < data.size(); c++) {
    if (data[c] != tmp[c])
      rem[data[c]][tmp[c]]++;
  }
  int swap = 0, left = 0;

  for (int c = 1; c <= 3; c++)
    for (int c2 = c + 1; c2 <= 3; c2++) {
      int mn = min(rem[c][c2], rem[c2][c]);
      rem[c][c2] -= mn;
      rem[c2][c] -= mn;
      swap += mn;
    }
  left = 2 * min(rem[1][2] + rem[1][3],
                 min(rem[2][1] + rem[2][3], rem[3][1] + rem[3][2]));
  printf("%d\n", swap + left);
}