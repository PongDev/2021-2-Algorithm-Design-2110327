#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, k, ans = 0;

    scanf("%d%d%d", &n, &w, &k);
    w++;
    vector<int> dp[2];
    vector<vector<int> *> vec[2];
    dp[0].resize(n + 1);
    dp[1].resize(n + 1);
    vec[0].assign(n + 1, NULL);
    vec[1].assign(n + 1, NULL);
    for (int c = 0; c < 2; c++)
        for (int c2 = 1; c2 <= n; c2++)
            scanf("%d", &dp[c][c2]);
    for (int c = 1; c <= n; c++) {
        for (int c2 = 0; c2 < 2; c2++) {
            if (c - w > 0) {
                int sameRow = dp[c2][c - 1] + (dp[c2][c] > vec[c2][c - 1]->back() ? dp[c2][c] - vec[c2][c - 1]->back() : 0);
                int opposRow = dp[c2][c] + dp[(c2 + 1) % 2][c - w] - (vec[(c2 + 1) % 2][c - w]->size() >= k ? min(dp[c2][c], (*vec[(c2 + 1) % 2][c - w])[vec[(c2 + 1) % 2][c - w]->size() - k]) : 0);

                if (opposRow > sameRow || (opposRow == sameRow && max((int)vec[(c2 + 1) % 2][c - w]->size(), k) < max((int)vec[c2][c - 1]->size(), k))) {
                    vec[c2][c] = vec[(c2 + 1) % 2][c - w];
                    if (vec[(c2 + 1) % 2][c - w]->size() < k || (vec[(c2 + 1) % 2][c - w]->size() >= k && (*vec[(c2 + 1) % 2][c - w])[vec[(c2 + 1) % 2][c - w]->size() - k] < dp[c2][c]))
                        vec[c2][c]->push_back(dp[c2][c]);
                    dp[c2][c] = opposRow;
                } else {
                    if (dp[c2][c] > vec[c2][c - 1]->back()) {
                        vec[c2][c] = new vector<int>;
                        *vec[c2][c] = *vec[c2][c - 1];
                        vec[c2][c]->back() = dp[c2][c];
                    } else
                        vec[c2][c] = vec[c2][c - 1];
                    dp[c2][c] = sameRow;
                }
            } else {
                vec[c2][c] = new vector<int>;
                vec[c2][c]->push_back(dp[c2][c]);
            }
        }
        ans = max(ans, max(dp[0][c], dp[1][c]));
    }
    printf("%d\n", ans);
}