#include <bits/stdc++.h>

using namespace std;

void findAnswer(int lv, int k, int current1, bool isOk, vector<bool> &bit) {
    if (lv == bit.size()) {
        if (isOk) {
            for (auto i : bit)
                printf("%d", i ? 1 : 0);
            printf("\n");
        }
    } else {
        bit[lv] = 0;
        findAnswer(lv + 1, k, 0, isOk, bit);
        bit[lv] = 1;
        findAnswer(lv + 1, k, current1 + 1, isOk || (current1 + 1 >= k), bit);
    }
}

int main() {
    int n, k;

    scanf("%d%d", &n, &k);
    vector<bool> bit(n);
    findAnswer(0, k, 0, false, bit);
}