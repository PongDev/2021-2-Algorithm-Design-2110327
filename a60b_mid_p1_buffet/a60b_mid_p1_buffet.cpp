#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, w, n, cur = 0, ans = 0;

    scanf("%d%d%d", &f, &w, &n);
    vector<int> data(f);
    for (auto &i : data)
        scanf("%d", &i);
    sort(data.begin(), data.end());
    w += w;
    for (auto &i : data) {
        if (cur < i) {
            cur = i + w;
            ans++;
        }
    }
    printf("%d\n", ans);
}