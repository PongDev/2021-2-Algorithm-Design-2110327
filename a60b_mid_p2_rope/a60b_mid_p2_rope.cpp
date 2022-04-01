#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;

    scanf("%d", &n);
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int c = 0; c < 3; c++) {
        scanf("%d", &i);
        for (int c2 = i; c2 <= n; c2++)
            if (dp[c2 - i] != -1)
                dp[c2] = max(dp[c2], dp[c2 - i] + 1);
    }
    printf("%d\n", dp[n]);
}