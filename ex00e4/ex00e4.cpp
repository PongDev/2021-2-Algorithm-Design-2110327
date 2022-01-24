#include <bits/stdc++.h>

using namespace std;

void findAnswer(int lv, int k, int used1, vector<bool> &bit) {
    if (lv == bit.size()) {
        if (used1 == k) {
            for (auto i : bit)
                printf("%d", i ? 1 : 0);
            printf("\n");
        }
    } else {
        bit[lv] = 0;
        findAnswer(lv + 1, k, used1, bit);
        bit[lv] = 1;
        findAnswer(lv + 1, k, used1 + 1, bit);
    }
}

int main() {
    int k, n;

    scanf("%d%d", &k, &n);
    vector<bool> bit(n);
    findAnswer(0, k, 0, bit);
}