#include <bits/stdc++.h>

using namespace std;

long long findAnswer(vector<int> &data, int l, int r, int A, long long B) {
    int count = lower_bound(data.begin(), data.end(), r) - lower_bound(data.begin(), data.end(), l);

    if (r - l == 1)
        return count > 0 ? B * count * (r - l) : A;
    else
        return count == 0 ? A : min(count > 0 ? B * count * (r - l) : A, findAnswer(data, l, (l + r) / 2, A, B) + findAnswer(data, (l + r) / 2, r, A, B));
}

int main() {
    int p, k, A, B;

    scanf("%d%d%d%d", &p, &k, &A, &B);
    vector<int> data(k);
    for (auto &i : data) {
        scanf("%d", &i);
        i--;
    }
    sort(data.begin(), data.end());
    printf("%lld\n", findAnswer(data, 0, 1 << p, A, B));
}