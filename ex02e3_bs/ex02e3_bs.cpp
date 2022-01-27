#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i;

    scanf("%d%d", &n, &m);
    vector<int> dat(n);
    for (int c = 0; c < n; c++)
        scanf("%d", &dat[c]);
    while (m--) {
        scanf("%d", &i);
        int l = 0, r = dat.size(), mid, remmid, ans = -1;

        mid = (l + r) / 2;
        remmid = -1;
        while (remmid != mid) {
            remmid = mid;
            if (dat[mid] <= i) {
                ans = max(mid, ans);
                l = mid;
            } else {
                r = mid;
            }
            mid = (l + r) / 2;
        }
        printf("%d\n", ans);
    }
}