#include <bits/stdc++.h>

int findLv(int lv) {
    int r = 3;

    for (int c = 0; c < lv; c++)
        r = (2 * r) + c + 4;
    return r;
}

int findG(int lv, int count, int n) {
    if (count >= n)
        return lv;
    else
        return findG(lv + 1, (2 * count) + lv + 4, n);
}

char findAnswer(int n) {
    if (n <= 3)
        return n == 1 ? 'g' : 'a';
    int g = findG(0, 3, n);
    int lv = findLv(g);
    int lowLv = findLv(g - 1);
    int diffG = n - lowLv;

    if (diffG <= g + 3)
        return diffG == 1 ? 'g' : 'a';
    else
        return findAnswer(diffG - (g + 3));
}

int main() {
    int n;

    scanf("%d", &n);
    printf("%c\n", findAnswer(n));
}