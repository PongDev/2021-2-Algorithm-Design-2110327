#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, iu, iv;
  vector<vector<bool>> mp(1001, vector<bool>(1001, false));
  vector<vector<int>> rem(1001, vector<int>(1001, INT_MAX));
  typedef pair<int, pair<int, int>> T;
  priority_queue<T, vector<T>, greater<T>> pq;

  scanf("%d%d%d", &n, &a, &b);
  for (int c = 0; c < n; c++) {
    scanf("%d%d", &iu, &iv);
    mp[iu][iv] = true;
  }
  pq.push({0, {a, b}});
  while (!pq.empty()) {
    int cost = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();
    if (cost < rem[x][y]) {
      if (x == 1 || y == 1 || x == 1000 || y == 1000) {
        printf("%d\n", cost);
        break;
      }
      rem[x][y] = cost;
      pq.push({cost + mp[x + 1][y], {x + 1, y}});
      pq.push({cost + mp[x - 1][y], {x - 1, y}});
      pq.push({cost + mp[x][y + 1], {x, y + 1}});
      pq.push({cost + mp[x][y - 1], {x, y - 1}});
    }
  }
}