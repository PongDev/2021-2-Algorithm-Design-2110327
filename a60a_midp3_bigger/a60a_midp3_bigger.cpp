#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    scanf("%d", &n);
    vector<int> dp(n);
    for (int c = 0; c < n; c++) {
        scanf("%d", &dp[c]);
        dp[c] = max(dp[c] + (c - 3 >= 0 ? dp[c - 3] : 0), max((c - 1 >= 0 ? dp[c - 1] : 0), (c - 2 >= 0 ? dp[c - 2] : 0)));
    }
    printf("%d\n", dp.back());
}