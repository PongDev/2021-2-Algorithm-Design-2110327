#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 1, mx;

    scanf("%d", &n);
    vector<pair<int, int>> data(n);
    for (auto &i : data)
        scanf("%d%d", &i.first, &i.second);
    sort(data.begin(), data.end(), greater<pair<int, int>>());
    mx = data[0].second;
    for (int c = 1; c < data.size(); c++)
        if (data[c].second > mx) {
            mx = data[c].second;
            ans++;
        }
    printf("%d\n", ans);
}