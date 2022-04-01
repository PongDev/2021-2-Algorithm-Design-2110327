#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0, cur = 0;

    scanf("%d", &n);
    vector<pair<int, int>> data(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &i : data)
        scanf("%d", &i.first);
    for (auto &i : data)
        scanf("%d", &i.second);
    for (auto &i : data) {
        pq.push({i.second, i.first});
    }
    while (!pq.empty()) {
        if (pq.top().second >= cur) {
            cur = pq.top().first;
            ans++;
        }
        pq.pop();
    }
    printf("%d\n", ans);
}