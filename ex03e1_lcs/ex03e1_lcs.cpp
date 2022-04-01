#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    vector<vector<int>> dp;

    cin >> a;
    cin >> b;
    dp.resize(a.size() + 1);
    for (vector<int> &vec : dp)
        vec.resize(b.size() + 1);
    for (int c = 1; c <= a.size(); c++)
        for (int c2 = 1; c2 <= b.size(); c2++)
            dp[c][c2] = (a[c - 1] == b[c2 - 1]) ? 1 + dp[c - 1][c2 - 1] : max(dp[c - 1][c2], dp[c][c2 - 1]);
    printf("%d\n", dp[a.size()][b.size()]);
}