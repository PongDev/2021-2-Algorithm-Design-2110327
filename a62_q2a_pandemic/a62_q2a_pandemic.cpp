#include <bits/stdc++.h>

#define x front().first.first
#define y front().first.second
#define time front().second

using namespace std;

int main() {
  int row, col, t, ans = 0;

  scanf("%d%d%d", &row, &col, &t);
  vector<vector<int>> data(row, vector<int>(col, 0));
  queue<pair<pair<int, int>, int>> q;
  for (int c = 0; c < data.size(); c++)
    for (int c2 = 0; c2 < data[c].size(); c2++) {
      scanf("%d", &data[c][c2]);
      if (data[c][c2] == 1)
        data[c][c2] = 0, q.push({{c, c2}, 0});
    }
  while (!q.empty()) {
    if (q.x >= 0 && q.x < row && q.y >= 0 && q.y < col && q.time <= t &&
        data[q.x][q.y] == 0) {
      ans++;
      data[q.x][q.y] = 1;
      q.push({{q.x + 1, q.y}, q.time + 1});
      q.push({{q.x - 1, q.y}, q.time + 1});
      q.push({{q.x, q.y + 1}, q.time + 1});
      q.push({{q.x, q.y - 1}, q.time + 1});
    }
    q.pop();
  }
  printf("%d\n", ans);
}