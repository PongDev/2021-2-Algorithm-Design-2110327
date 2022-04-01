#include <bits/stdc++.h>

int main() {
    int n;

    scanf("%d", &n);
    std::vector<int> data(n + 1);
    data[0] = 0;
    data[1] = 1;
    for (int c = 2; c <= n; c++)
        data[c] = data[c - 1] + data[c - 2];
    printf("%d\n", data[n]);
}