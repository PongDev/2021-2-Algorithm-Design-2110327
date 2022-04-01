#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q, x1, y1, x2, y2;

    scanf("%d%d%d", &n, &m, &q);
    vector<vector<int>> dp(n + 1);
    dp[0].resize(m + 1);
    for (int c = 1; c <= n; c++) {
        dp[c].resize(m + 1);
        for (int c2 = 1; c2 <= m; c2++) {
            scanf("%d", &dp[c][c2]);
            dp[c][c2] += dp[c - 1][c2] + dp[c][c2 - 1] - dp[c - 1][c2 - 1];
        }
    }
    while (q--) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++;
        y1++;
        x2++;
        y2++;
        printf("%d\n", dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1] - dp[x1 - 1][y2]);
    }
}