#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0, maxEle, ans = INT_MIN;

    scanf("%d", &n);
    vector<int> dp(n), dp2(n);
    for (int c = 0; c < n; c++) {
        scanf("%d", &dp[c]);
        dp2[c] = dp[c];
        sum += dp[c];
    }
    maxEle = dp[0];
    for (auto &i : dp)
        maxEle = max(maxEle, i);
    if (maxEle < 0)
        printf("%d\n", maxEle);
    else {
        for (int c = 1; c < n; c++) {
            dp[c] = max(dp[c] + dp[c - 1], dp[c]);
            dp2[c] = min(dp2[c] + dp2[c - 1], dp2[c]);
            ans = max(ans, max(dp[c], sum - dp2[c]));
        }
        printf("%d\n", ans);
    }
}