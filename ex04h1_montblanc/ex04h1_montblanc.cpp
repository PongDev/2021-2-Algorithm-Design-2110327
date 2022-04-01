#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, l = 0, r, mid, remmid, ans1 = INT_MAX, ans2 = 0;

    scanf("%d%d", &n, &m);
    vector<int> data(n + 1);
    for (int c = 1; c <= n; c++)
        scanf("%d", &data[c]), l = max(l, data[c] - data[c - 1]);
    r = data.back() + 1;
    mid = (l + r) / 2;
    remmid = -1;
    while (remmid != mid) {
        remmid = mid;
        int tmp = 1;
        int pos = 1;
        int power = mid;
        while (pos <= n) {
            if (power >= data[pos] - data[pos - 1]) {
                power -= data[pos] - data[pos - 1];
                pos++;
            } else {
                power = mid;
                tmp++;
            }
        }
        if (tmp <= m && mid <= ans1 && tmp >= ans2) {
            r = mid;
            ans1 = mid;
            ans2 = tmp;
        } else
            l = mid;
        mid = (l + r) / 2;
    }
    printf("%d %d\n", ans1, ans2);
}