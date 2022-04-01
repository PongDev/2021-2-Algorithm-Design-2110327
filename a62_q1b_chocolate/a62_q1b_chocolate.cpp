#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    const int mod = 1000003;

    scanf("%d%d", &n, &m);
    vector<int> data(m), dp(n + 1);
    for (auto &i : data)
        scanf("%d", &i);
    dp[0] = 1;
    for (int c = 0; c <= n; c++)
        for (auto &i : data)
            if (c - i >= 0) {
                dp[c] += dp[c - i];
                dp[c] %= mod;
            }
    printf("%d\n", dp[n]);
}