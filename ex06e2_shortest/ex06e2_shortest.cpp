#include <bits/stdc++.h>

#define w first
#define u second.first
#define v second.second

using namespace std;

int main() {
  int n, m, st;
  bool isNegCycle = false;

  scanf("%d%d%d", &n, &m, &st);
  vector<pair<int, pair<int, int>>> el(m);
  vector<int> d(n, INT_MAX / 2);

  d[st] = 0;
  for (auto &i : el)
    scanf("%d%d%d", &i.u, &i.v, &i.w);
  for (int c = 0; c < n - 1; c++)
    for (auto &i : el)
      d[i.v] = min(d[i.v], d[i.u] + i.w);
  for (auto &i : el)
    if (d[i.u] + i.w < d[i.v]) {
      printf("-1");
      isNegCycle = true;
      break;
    }
  if (!isNegCycle)
    for (auto &i : d)
      printf("%d ", i);
  printf("\n");
}
