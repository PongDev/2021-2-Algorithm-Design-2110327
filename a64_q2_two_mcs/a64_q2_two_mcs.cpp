#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, primaryAnswer = INT_MIN, secondaryAnswer = INT_MIN, primaryL, primaryR;

    scanf("%d", &n);
    vector<int> data(n + 1), dp2(n + 1);
    vector<pair<int, int>> dp(n + 1);
    for (size_t c = 1; c <= n; c++) {
        scanf("%d", &dp[c].first);
        dp[c].second = 1;
        dp2[c] = dp[c].first;
        if (dp[c].first + dp[c - 1].first > dp[c].first) {
            dp[c].first += dp[c - 1].first;
            dp[c].second += dp[c - 1].second;
        }
        if (dp[c].first > primaryAnswer) {
            primaryAnswer = dp[c].first;
            primaryL = c - dp[c].second + 1;
            primaryR = c;
        }
    }
    for (int c = 1; c <= n; c++)
        if (c < primaryL || c - 1 > primaryR) {
            dp2[c] = max(dp2[c], dp2[c] + dp2[c - 1]);
            secondaryAnswer = max(secondaryAnswer, dp2[c]);
        }
    printf("%d\n", primaryAnswer + max(secondaryAnswer, 0));
}