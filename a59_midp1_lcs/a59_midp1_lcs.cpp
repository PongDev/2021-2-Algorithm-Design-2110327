#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, row, col;
    string str[2];

    scanf("%d%d", &n, &m);
    cin >> str[0] >> str[1];
    vector<vector<int>> dp(n + 1);
    for (auto &vec : dp)
        vec.resize(m + 1);
    for (auto &vec : dp)
        for (auto &i : vec)
            scanf("%d", &i);
    stack<char> stk;
    row = n;
    col = m;
    while (row != 0 && col != 0) {
        if (str[0][row - 1] == str[1][col - 1]) {
            stk.push(str[0][row - 1]);
            row--;
            col--;
        } else if (dp[row - 1][col] > dp[row][col - 1])
            row--;
        else
            col--;
    }
    while (!stk.empty()) {
        printf("%c", stk.top());
        stk.pop();
    }
    printf("\n");
}