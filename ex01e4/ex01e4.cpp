#include <bits/stdc++.h>

int modexpo(int x, int n, int k) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x % k;
    else {
        int r = modexpo(x, n / 2, k) % k;
        r *= r;
        r %= k;
        if (n % 2) {
            r *= x;
            r %= k;
        }
        return r;
    }
}

int main() {
    int x, n, k;

    scanf("%d%d%d", &x, &n, &k);
    printf("%d\n", modexpo(x, n, k));
}