#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;

    scanf("%d", &n);
    vector<int> data[2];
    data[0].resize(n);
    data[1].resize(n);
    scanf("%d", &data[0][0]);
    for (int c = 1; c < n; c++) {
        for (int c2 = 0; c2 <= c; c2++) {
            scanf("%d", &i);
            data[c % 2][c2] = i + max(data[(c + 1) % 2][c2], c2 - 1 >= 0 ? data[(c + 1) % 2][c2 - 1] : 0);
        }
    }
    printf("%d\n", *max_element(data[(n + 1) % 2].begin(), data[(n + 1) % 2].end()));
}