#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a;
    long long k, b;

    scanf("%d%d%lld", &n, &m, &k);
    vector<int> data(n + 1), qs(n + 1);
    for (int c = 1; c < data.size(); c++) {
        scanf("%d", &data[c]);
        qs[c] = data[c] + qs[c - 1];
    }

    static const auto calc = [&](int l, int r) {
        return qs[min(r, (int)qs.size() - 1)] - qs[l - 1];
    };

    while (m--) {
        scanf("%d%lld", &a, &b);
        a += 1;

        int l = a, r = n + 1;
        int mid = (l + r) / 2, remmid = -1;
        int ans = 0;

        while (mid != remmid) {
            int sum = calc(a, mid);

            if (sum + ((mid - a + 1) * k) <= b)
                l = mid, ans = max(ans, sum);
            else
                r = mid;
            remmid = mid;
            mid = (l + r) / 2;
        }
        printf("%d\n", ans);
    }
}