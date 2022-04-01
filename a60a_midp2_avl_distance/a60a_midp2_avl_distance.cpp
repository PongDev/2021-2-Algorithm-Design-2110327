#include <bits/stdc++.h>

using namespace std;

void genDP(vector<vector<int>> &gph, int node, vector<vector<int>> &dp) {
    dp[node][0] = 1;
    if (gph[node].size() == 0)
        return;
    else {
        for (auto &i : gph[node]) {
            genDP(gph, i, dp);
            for (int c = 1; c <= 500; c++) {
                dp[node][c] += dp[i][c - 1];
            }
        }
    }
}

int findAnswer(vector<vector<int>> &gph, vector<vector<int>> &dp, int k, int node, int parent) {
    int r = 0;

    for (auto &i : gph[node]) {
        r += findAnswer(gph, dp, k, i, node) + dp[i][k - 1];
    }
    if (gph[node].size() == 2) {
        for (int c = 0; c <= k - 2; c++) {
            r += dp[gph[node][0]][c] * dp[gph[node][1]][k - 2 - c];
        }
    }
    return r;
}

int main() {
    int n, k, u, v;

    scanf("%d%d", &n, &k);
    vector<vector<int>> gph(n + 1), dp(n + 1);
    for (auto &vec : dp)
        vec.resize(501);
    for (int c = 1; c < n; c++) {
        scanf("%d%d", &u, &v);
        gph[u].push_back(v);
    }
    genDP(gph, 1, dp);
    printf("%d\n", findAnswer(gph, dp, k, 1, -1));
}