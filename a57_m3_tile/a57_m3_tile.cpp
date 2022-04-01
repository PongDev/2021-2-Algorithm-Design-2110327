#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    vector<int> data(n);
    for (auto &i : data)
        scanf("%d", &i);
    sort(data.begin(), data.end());
    vector<vector<int>> dp(n + 1);
    dp[0].assign(m + 1, INT_MAX);
    dp[0][0] = 0;
    for (int c = 1; c <= n; c++) {
        dp[c].assign(m + 1, INT_MAX);
        for (int c2 = 1; c2 <= 100; c2++) {
            int tmp = c2 * c2;
            for (int c3 = tmp; c3 <= m; c3++)
                if (dp[c - 1][c3 - tmp] != INT_MAX)
                    dp[c][c3] = min(dp[c][c3], dp[c - 1][c3 - tmp] + (abs(data[c - 1] - c2) * abs(data[c - 1] - c2)));
        }
    }
    printf("%d\n", dp[n][m] == INT_MAX ? -1 : dp[n][m]);
}