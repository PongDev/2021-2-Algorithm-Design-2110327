#include <bits/stdc++.h>

using namespace std;

long long inversion_count(vector<int> &data, vector<int> &tmp, int l, int r) {
    if (l >= r)
        return 0;
    else {
        long long ret = 0;

        ret += inversion_count(data, tmp, l, (l + r) / 2);
        ret += inversion_count(data, tmp, ((l + r) / 2) + 1, r);
        for (int c = l; c <= r; c++)
            tmp[c] = data[c];
        int pos1 = l, pos2 = ((l + r) / 2) + 1, idx = l;

        while (idx <= r) {
            if (pos1 <= (l + r) / 2 && tmp[pos1] < tmp[pos2])
                data[idx++] = tmp[pos1++];
            else if (pos2 <= r && tmp[pos2] < tmp[pos1])
                data[idx++] = tmp[pos2++], ret += ((l + r) / 2) - pos1 + 1;
            else {
                if (pos1 <= (l + r) / 2)
                    data[idx++] = tmp[pos1++];
                else if (pos2 <= r)
                    data[idx++] = tmp[pos2++];
            }
        }
        return ret;
    }
}

int main() {
    int n;

    scanf("%d", &n);
    vector<int> data(n), tmp(n);
    for (int c = 0; c < n; c++)
        scanf("%d", &data[c]);
    printf("%lld\n", inversion_count(data, tmp, 0, data.size() - 1));
}