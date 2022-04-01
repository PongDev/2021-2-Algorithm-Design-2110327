#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, item, weight;

    scanf("%d%d", &n, &w);
    vector<pair<int, int>> data(n + 1);
    vector<vector<int>> dp(n + 1);
    for (auto &vec : dp)
        vec.resize(w + 1);
    for (int c = 1; c <= n; c++)
        scanf("%d", &data[c].first);
    for (int c = 1; c <= n; c++)
        scanf("%d", &data[c].second);
    for (int c = 0; c <= n; c++)
        for (int c2 = 0; c2 <= w; c2++)
            scanf("%d", &dp[c][c2]);
    stack<int> stk;
    item = n;
    weight = w;
    while (item > 0) {
        if (weight >= data[item].second && dp[item - 1][weight - data[item].second] == dp[item][weight] - data[item].first) {
            stk.push(item);
            weight -= data[item].second;
        }
        item--;
    }

    printf("%d\n", stk.size());
    while (!stk.empty()) {
        printf("%d ", stk.top());
        stk.pop();
    }
    printf("\n");
}