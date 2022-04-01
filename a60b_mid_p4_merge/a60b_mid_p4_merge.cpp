#include <bits/stdc++.h>

using namespace std;

bool findAns(vector<int> &data, int k, int l, int r) {
    if (l >= r - 1)
        return k == 0;
    else if (k == 0)
        return true;
    else if (k >= 2) {
        int mid = (l + r) / 2;

        // for (int i = l; i < mid; i++)
        //     swap(data[i], data[mid + i - l]);
        swap(data[mid - 1], data[mid]);
        k -= 2;
        if ((k / 2) % 2 == 0)
            return findAns(data, k / 2, l, mid) && findAns(data, (k / 2) + (k % 2), mid, r);
        else
            return findAns(data, (k / 2) - 1, l, mid) && findAns(data, (k / 2) + (k % 2) + 1, mid, r);
    } else
        return false;
}

int main() {
    int n, k;

    scanf("%d%d", &n, &k);
    vector<int> data(n);
    for (int i = 0; i < n; i++)
        data[i] = i + 1;
    bool isFind = findAns(data, k - 1, 0, n);
    if (isFind) {
        for (auto i : data) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}