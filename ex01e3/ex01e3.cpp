#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i;

    scanf("%d%d", &n, &m);
    vector<int> data(n);
    for (int c = 0; c < n; c++)
        scanf("%d", &data[c]);
    while (m--) {
        scanf("%d", &i);
        int idx = upper_bound(data.begin(), data.end(), i) - data.begin() - 1;
        printf("%d\n", idx == -1 ? idx : data[idx]);
    }
}