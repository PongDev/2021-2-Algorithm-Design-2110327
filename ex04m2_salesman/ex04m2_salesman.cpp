#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x, y, sum = 0, ans;

    scanf("%d%d", &n, &m);
    vector<int> data(m), qs(m + 1);
    for (auto &i : data)
        scanf("%d", &i);
    for (int c = 1; c <= m; c++) {
        scanf("%d", &qs[c]);
        sum += qs[c];
        qs[c] += qs[c - 1];
    }
    auto minDist = [&](int a, int b) {
        a++;
        b++;
        if (a > b)
            swap(a, b);
        return min(qs[b - 1] - qs[a - 1], sum - (qs[b - 1] - qs[a - 1]));
    };
    while (n--) {
        ans = 0;
        scanf("%d%d", &x, &y);
        for (int c = 0; c < m; c++) {
            ans += min(minDist(data[c], data[(c + 1) % m]), min(minDist(data[c], x) + minDist(y, data[(c + 1) % m]), minDist(data[c], y) + minDist(x, data[(c + 1) % m])));
        }
        printf("%d\n", ans);
    }
}