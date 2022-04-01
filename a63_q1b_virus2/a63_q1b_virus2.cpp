#include <bits/stdc++.h>

using namespace std;

int count1(vector<int> &data, int l, int r) {
    if (l == r)
        return data[l];
    else {
        int x = count1(data, l, l + ((r - l + 1) / 2) - 1);
        int y = count1(data, l + ((r - l + 1) / 2), r);
        if (x == -1 || y == -1)
            return -1;
        else
            return abs(x - y) <= 1 ? x + y : -1;
    }
}

int main() {
    int q, k;

    scanf("%d%d", &q, &k);
    vector<int> data(1 << k);
    while (q--) {
        for (int c = 0; c < 1 << k; c++)
            scanf("%d", &data[c]);
        printf("%s\n", count1(data, 0, (1 << k) - 1) != -1 ? "yes" : "no");
        data.clear();
    }
}