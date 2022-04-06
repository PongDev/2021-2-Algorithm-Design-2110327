#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, i;

  scanf("%d", &n);
  vector<vector<int>> gph(n);
  vector<int> degree(n);
  queue<int> q;
  for (int c = 0; c < n; c++) {
    scanf("%d", &degree[c]);
    for (int c2 = 0; c2 < degree[c]; c2++)
      scanf("%d", &i), gph[i].push_back(c);
    if (degree[c] == 0)
      q.push(c);
  }
  while (!q.empty()) {
    printf("%d ", q.front());
    for (auto &i : gph[q.front()]) {
      degree[i]--;
      if (degree[i] == 0)
        q.push(i);
    }
    q.pop();
  }
  printf("\n");
}