#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i;

    scanf("%d%d", &n, &m);
    vector<vector<int>> dp(n);
    for (int c = 0; c < n; c++) {
        dp[c].resize(m);
        for (int c2 = 0; c2 < m; c2++) {
            scanf("%d", &i);
            if (c == 0 && c2 == 0)
                dp[c][c2] = i;
            if (c - 1 >= 0 && c2 - 1 >= 0)
                dp[c][c2] = max(dp[c][c2], (i * 2) + dp[c - 1][c2 - 1]);
            if (c - 1 >= 0)
                dp[c][c2] = max(dp[c][c2], i + dp[c - 1][c2]);
            if (c2 - 1 >= 0)
                dp[c][c2] = max(dp[c][c2], i + dp[c][c2 - 1]);
        }
    }
    printf("%d\n", dp[n - 1][m - 1]);
}