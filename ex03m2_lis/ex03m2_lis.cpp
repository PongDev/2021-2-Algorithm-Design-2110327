#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;

    scanf("%d", &n);
    vector<int> data(n), dp(n);
    for (int c = 0; c < n; c++) {
        scanf("%d", &data[c]);
        dp[c] = 1;
        for (int c2 = 0; c2 < c; c2++)
            if (data[c] > data[c2])
                dp[c] = max(dp[c], 1 + dp[c2]);
        ans = max(ans, dp[c]);
    }
    printf("%d\n", ans);
}