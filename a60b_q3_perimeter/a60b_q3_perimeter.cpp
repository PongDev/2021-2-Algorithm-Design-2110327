#include <bits/stdc++.h>

#define node front().first
#define cost front().second

using namespace std;

int main() {
  int n, m, k, iu, iv, ans = 0;

  scanf("%d%d%d", &n, &m, &k);
  vector<vector<int>> gph(n + 1);
  vector<bool> rem(n + 1);
  queue<pair<int, int>> q;
  q.push({0, 0});
  for (int c = 0; c < m; c++) {
    scanf("%d%d", &iu, &iv);
    gph[iu].push_back(iv);
    gph[iv].push_back(iu);
  }
  while (!q.empty()) {
    if (q.cost <= k && !rem[q.node]) {
      rem[q.node] = true;
      ans += (q.cost == k);
      for (auto &i : gph[q.node])
        q.push({i, q.cost + 1});
    }
    q.pop();
  }
  printf("%d\n", ans);
}