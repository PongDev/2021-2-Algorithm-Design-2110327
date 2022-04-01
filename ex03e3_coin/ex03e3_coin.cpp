#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i;

    scanf("%d%d", &n, &m);
    vector<int> dp(m + 1);
    for (int c = 1; c <= m; c++)
        dp[c] = c;
    for (int c = 0; c < n; c++) {
        scanf("%d", &i);
        if (i <= m)
            for (int c2 = i; c2 <= m; c2++)
                dp[c2] = min(dp[c2], dp[c2 - i] + 1);
    }
    printf("%d\n", dp[m]);
}