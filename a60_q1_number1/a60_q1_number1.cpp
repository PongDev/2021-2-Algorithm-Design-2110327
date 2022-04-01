#include <bits/stdc++.h>

using namespace std;

int findSplitSize(int n, map<int, int> &splitSize) {
    if (n == 1)
        return 1;
    else if (splitSize.count(n) == 0)
        splitSize[n] = (2 * findSplitSize(n / 2, splitSize)) + 1;
    return splitSize[n];
}

int findAns(int n, map<int, int> &splitSize, int l, int r) {
    int ans = 0, splitSizeN = splitSize[n];

    if (l == r)
        return 1;
    if (l <= (splitSizeN / 2) + 1 && (splitSizeN / 2) + 1 <= r)
        ans += n % 2;
    if (l < (splitSizeN / 2) + 1)
        ans += findAns(n / 2, splitSize, l, min(r, (splitSizeN / 2)));
    if (r > (splitSizeN / 2) + 1)
        ans += findAns(n / 2, splitSize, max(1, l - (splitSizeN / 2) - 1), r - (splitSizeN / 2) - 1);
    return ans;
}

int main() {
    int n, l, r;
    map<int, int> splitSize;

    scanf("%d%d%d", &n, &l, &r);
    findSplitSize(n, splitSize);
    printf("%d\n", findAns(n, splitSize, l, r));
}