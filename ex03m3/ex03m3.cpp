#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, ans = INT_MAX;

    scanf("%d%d", &n, &k);
    vector<int> dp(n);
    for (int c = 0; c < n; c++)
        scanf("%d", &dp[c]);
    for (int c = 0; c < n; c++) {
        int minCost = INT_MAX;
        for (int c2 = max(c - 1 - (2 * k), 0); c2 < c; c2++)
            minCost = min(minCost, dp[c2]);
        dp[c] += c > k ? minCost : 0;
        if (c >= n - 1 - k)
            ans = min(ans, dp[c]);
    }
    printf("%d\n", ans);
}