#include <bits/stdc++.h>

using namespace std;

int find(vector<vector<int>> &dp, int n, int k) {
    if (n == k || k == 0)
        return 1;
    else if (1 <= k && k <= n - 1) {
        if (dp[n][k] == 0)
            dp[n][k] = find(dp, n - 1, k - 1) + find(dp, n - 1, k);
        return dp[n][k];
    } else
        return 0;
}

int main() {
    int n, k;

    scanf("%d%d", &n, &k);
    vector<vector<int>> dp(n + 1);
    for (vector<int> &vec : dp)
        vec.resize(k + 1);
    printf("%d\n", find(dp, n, k));
}