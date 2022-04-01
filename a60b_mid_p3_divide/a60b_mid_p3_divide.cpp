#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    const int mod = 1997;

    scanf("%d%d", &n, &k);
    vector<vector<int>> dp(n + 1);
    for (int c = 1; c <= n; c++) {
        dp[c].resize(c + 1);
        dp[c][1] = dp[c][c] = 1;
        for (int c2 = 2; c2 < c; c2++)
            dp[c][c2] = (dp[c - 1][c2 - 1] + (dp[c - 1][c2] * c2)) % mod;
    }
    printf("%d\n", dp[n][k]);
}