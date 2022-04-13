#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k, iu, iv;

  scanf("%lld", &n);
  map<long long, vector<long long>> gph;
  map<long long, long long> score;
  for (long long c = 0; c < n; c++) {
    scanf("%lld%lld", &iu, &iv);
    gph[iv].push_back(iu);
  }
  scanf("%lld", &k);
  for (auto &node : gph) {
    for (auto &mother : gph[node.first]) {
      for (auto &grandmother : gph[mother])
        score[grandmother]++;
    }
  }
  priority_queue<pair<long long, long long>> pq;
  for (auto &i : score) {
    pq.push({-i.second, i.first});
    while (pq.size() > k)
      pq.pop();
  }
  stack<long long> stk;
  while (!pq.empty()) {
    stk.push(pq.top().second);
    pq.pop();
  }
  while (!stk.empty()) {
    printf("%lld\n", stk.top());
    stk.pop();
  }
}