#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    long long i;

    scanf("%d%d", &n, &m);
    vector<int> data(n);
    for (int c = 0; c < n; c++) {
        scanf("%d", &data[c]);
    }
    while (m--) {
        scanf("%lld", &i);
        long long l = 0, r = 1e15, mid, remmid, ans = 1e15;
        auto getCurrentCustomer = [&](long long v) {
            long long r = 0;

            for (auto &e : data)
                r += (v / e) + 1;
            return r;
        };

        mid = (l + r) / 2;
        remmid = -1;
        while (mid != remmid) {
            remmid = mid;
            if (getCurrentCustomer(mid) >= i) {
                ans = min(ans, mid);
                r = mid;
            } else {
                l = mid;
            }
            mid = (l + r) / 2;
        }
        printf("%lld\n", ans);
    }
}