#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, iu, iv, counter = 0;
  bool ans = false;

  scanf("%d", &n);
  vector<vector<int>> gph(n);
  vector<int> state(n, 0), depth(n, 0);
  for (int c = 0; c < n; c++) {
    scanf("%d%d", &iu, &iv);
    gph[iu].push_back(iv);
    gph[iv].push_back(iu);
  }
  auto dfs = [&](auto dfs, int node, int p) -> void {
    if (!ans && state[node] == 0) {
      state[node] = 1;
      counter++;
      depth[node] = counter;
      for (auto &i : gph[node])
        if (p != i)
          dfs(dfs, i, node);
      state[node] = 2;
      counter--;
    } else if (!ans && state[node] == 1) {
      ans = true;
      printf("%d\n", counter - depth[node] + 1);
    }
  };
  dfs(dfs, 0, -1);
}