#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;

    scanf("%d", &n);
    vector<int> dp(n);
    scanf("%d", &dp[0]);
    for (int c = 1; c < n; c++) {
        scanf("%d", &i);
        dp[c] = i + max(c - 1 >= 0 ? dp[c - 1] : INT_MIN, max(c - 2 >= 0 ? dp[c - 2] : INT_MIN, c - 3 >= 0 ? dp[c - 3] : INT_MIN));
    }
    printf("%d\n", dp.back());
}