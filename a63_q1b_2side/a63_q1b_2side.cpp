#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, k, ans = 0;

    scanf("%d%d%d", &n, &w, &k);
    w += 1;
    vector<int> dp[2];
    vector<priority_queue<int, vector<int>, greater<int>> *> pq[2];
    dp[0].resize(n + 1);
    dp[1].resize(n + 1);
    pq[0].assign(n + 1, NULL);
    pq[1].assign(n + 1, NULL);
    for (int c = 0; c < 2; c++)
        for (int c2 = 1; c2 <= n; c2++)
            scanf("%d", &dp[c][c2]);
    for (int c = 1; c <= n; c++) {
        if (c - w > 0) {
            for (int c2 = 0; c2 < 2; c2++) {
                int sameRow = dp[c2][c - 1] - (pq[c2][c - 1]->size() == k ? pq[c2][c - 1]->top() : 0);
                int opposRow = dp[c2][c] + dp[(c2 + 1) % 2][c - w] - (pq[(c2 + 1) % 2][c - w]->size() == k ? pq[(c2 + 1) % 2][c - w]->top() : 0);
                if (opposRow > sameRow || (opposRow == sameRow && pq[(c2 + 1) % 2][c - w]->size() < pq[c2][c - 1]->size())) {
                    pq[c2][c] = new priority_queue<int, vector<int>, greater<int>>();
                    *pq[c2][c] = *pq[(c2 + 1) % 2][c - w];
                    if (pq[c2][c]->size() == k)
                        pq[c2][c]->pop();
                    pq[c2][c]->push(dp[c2][c]);
                    dp[c2][c] = opposRow;
                } else {
                    pq[c2][c] = pq[c2][c - 1];
                    dp[c2][c] = sameRow;
                }
            }
        } else {
            for (int c2 = 0; c2 < 2; c2++) {
                if (dp[c2][c - 1] > dp[c2][c]) {
                    dp[c2][c] = dp[c2][c - 1];
                    pq[c2][c] = pq[c2][c - 1];
                } else {
                    pq[c2][c] = new priority_queue<int, vector<int>, greater<int>>();
                    pq[c2][c]->push(dp[c2][c]);
                }
            }
        }
        ans = max(ans, max(dp[0][c], dp[1][c]));
    }
    printf("%d\n", ans);
}