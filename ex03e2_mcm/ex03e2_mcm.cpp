#include <bits/stdc++.h>

using namespace std;

int findAns(vector<vector<int>> &dp, vector<int> &data, int l, int r) {
    if (r - l < 2)
        return 0;
    if (r - l == 2)
        return data[l] * data[l + 1] * data[l + 2];
    if (dp[l][r] == INT_MAX)
        for (int c = l + 1; c <= r - 1; c++)
            dp[l][r] = min(dp[l][r], (data[l] * data[c] * data[r]) + findAns(dp, data, l, c) + findAns(dp, data, c, r));
    return dp[l][r];
}

int main() {
    int n;

    scanf("%d", &n);
    n += 1;
    vector<int> data(n);
    vector<vector<int>> dp(n);
    for (auto &vec : dp)
        vec.assign(n, INT_MAX);
    for (auto &i : data)
        scanf("%d", &i);
    printf("%d\n", findAns(dp, data, 0, n - 1));
}