#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, iu, iv, tmp, ans = 0;
  bool isOK;

  scanf("%d%d", &n, &m);
  vector<vector<int>> gph(n);
  vector<bool> rem(n);
  for (int c = 0; c < m; c++) {
    scanf("%d%d", &iu, &iv);
    gph[iu].push_back(iv);
    gph[iv].push_back(iu);
  }
  auto dfs = [&](auto dfs, int node) -> void {
    if (!rem[node]) {
      rem[node] = true;
      if (gph[node].size() > 2)
        isOK = false;
      tmp += gph[node].size() == 1;
      for (auto &i : gph[node])
        dfs(dfs, i);
    }
  };
  for (int c = 0; c < n; c++) {
    tmp = 0;
    isOK = true;
    dfs(dfs, c);
    if (gph[c].size() == 0 || isOK && tmp == 2)
      ans++;
  }
  printf("%d\n", ans);
}