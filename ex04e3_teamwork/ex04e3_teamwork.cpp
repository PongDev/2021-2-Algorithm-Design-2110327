#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    long long sum = 0;

    scanf("%d%d", &n, &m);
    vector<int> data(m);
    for (auto &i : data)
        scanf("%d", &i);
    sort(data.begin(), data.end());
    for (int c = 0; c < m; c++) {
        if (c >= n)
            data[c] += data[c - n];
        sum += data[c];
    }
    printf("%.3lf\n", (double)sum / m);
}