#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, m, i, w, l, r, mid, remmid, ans;

    scanf("%d%d%d", &n, &k, &m);
    vector<int> data(n + 2);
    for (int c = 1; c <= n; c++) {
        scanf("%d", &data[c]);
        data[c] -= m;
        data[c] += data[c - 1];
    }
    while (k--) {
        scanf("%d%d", &i, &w);
        ans = n;
        l = i;
        r = n + 1;
        mid = (l + r) / 2;
        remmid = -1;
        while (mid != remmid) {
            remmid = mid;
            if (data[mid] - data[i - 1] >= w) {
                ans = min(ans, mid);
                r = mid;
            } else
                l = mid;
            mid = (l + r) / 2;
        }
        printf("%d\n", ans);
    }
}