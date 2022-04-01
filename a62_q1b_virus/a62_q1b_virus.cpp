#include <bits/stdc++.h>

using namespace std;

bool chk(vector<int> &data, int l, int r) {
    if (r - l == 1) {
        return data[l] == 0 && data[r] == 1;
    } else {
        reverse(data.begin() + l, data.begin() + l + ((r - l + 1) / 2));
        bool rev = chk(data, l, l + ((r - l + 1) / 2) - 1) && chk(data, l + ((r - l + 1) / 2), r);
        reverse(data.begin() + l, data.begin() + l + ((r - l + 1) / 2));
        bool normal = chk(data, l, l + ((r - l + 1) / 2) - 1) && chk(data, l + ((r - l + 1) / 2), r);
        return rev || normal;
    }
}

int main() {
    int q, k;

    scanf("%d%d", &q, &k);
    vector<int> data(1 << k);
    while (q--) {
        for (int c = 0; c < 1 << k; c++)
            scanf("%d", &data[c]);
        printf("%s\n", chk(data, 0, (1 << k) - 1) ? "yes" : "no");
    }
}