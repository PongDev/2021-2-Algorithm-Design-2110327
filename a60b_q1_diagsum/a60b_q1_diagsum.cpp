#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = INT_MIN;

    scanf("%d", &n);
    vector<vector<int>> dp(n);
    for (int c = 0; c < n; c++) {
        dp[c].resize(n);
        for (int c2 = 0; c2 < n; c2++) {
            scanf("%d", &dp[c][c2]);
            dp[c][c2] += max(0, c - 1 >= 0 && c2 - 1 >= 0 ? dp[c - 1][c2 - 1] : INT_MIN);
            ans = max(ans, dp[c][c2]);
        }
    }
    printf("%d\n", ans);
}