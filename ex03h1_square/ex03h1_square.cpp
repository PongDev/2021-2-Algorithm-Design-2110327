#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, ans = 0;

    scanf("%d%d", &n, &m);
    vector<vector<int>> data(n);
    for (auto &vec : data) {
        vec.resize(m);
        string i;

        cin >> i;
        for (int c2 = 0; c2 < m; c2++) {
            vec[c2] = (i[c2] == '1' ? 1 : 0);
            ans = max(ans, vec[c2]);
        }
    }
    for (int c = 1; c < n; c++)
        for (int c2 = 1; c2 < m; c2++) {
            if (data[c][c2]) {
                data[c][c2] = 1 + min(data[c - 1][c2 - 1], min(data[c - 1][c2], data[c][c2 - 1]));
                ans = max(ans, data[c][c2]);
            }
        }
    printf("%d\n", ans);
}