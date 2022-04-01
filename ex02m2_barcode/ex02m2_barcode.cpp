#include <bits/stdc++.h>

using namespace std;

int findAnswer(vector<vector<vector<vector<int>>>> &dp, int n, int m, int k, int lv, int consecutive, int change, int last) {
    if (lv == 0)
        return k == change;
    else if (dp[lv][consecutive][change][last] == 0 && k - change <= lv) {
        if (change < k)
            dp[lv][consecutive][change][last] += findAnswer(dp, n, m, k, lv - 1, 1, change + 1, !last);
        if (consecutive < m)
            dp[lv][consecutive][change][last] += findAnswer(dp, n, m, k, lv - 1, consecutive + 1, change, last);
    }
    return dp[lv][consecutive][change][last];
}

int main() {
    int n, m, k;

    scanf("%d%d%d", &n, &m, &k);
    vector<vector<vector<vector<int>>>> dp;
    dp.resize(n + 1);
    for (vector<vector<vector<int>>> &vec3d : dp) {
        vec3d.resize(m + 1);
        for (vector<vector<int>> &vec2d : vec3d) {
            vec2d.resize(k + 1);
            for (vector<int> &vec : vec2d)
                vec.resize(2);
        }
    }
    printf("%d\n", findAnswer(dp, n, m, k, n - 1, 1, 0, 0));
}