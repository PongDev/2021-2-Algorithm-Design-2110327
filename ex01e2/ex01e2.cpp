#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> maxsum(vector<int> &data, int l, int r) {
    if (l == r)
        return {data[l], data[l]};
    else {
        pair<long long, long long> prev = maxsum(data, l, r - 1);
        return {max(prev.first, max(prev.second + data[r], (long long)data[r])), max(prev.second + data[r], (long long)data[r])};
    }
}

int main() {
    int n;

    scanf("%d", &n);
    vector<int> data(n);
    for (int c = 0; c < n; c++)
        scanf("%d", &data[c]);
    printf("%lld\n", maxsum(data, 0, n - 1).first);
}