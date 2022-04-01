#include <bits/stdc++.h>

using namespace std;

int main() {
    double w, ans = 0;
    int n;

    scanf("%lf%d", &w, &n);
    vector<pair<double, pair<double, double>>> data(n);
    for (auto &i : data)
        scanf("%lf", &i.second.first);
    for (auto &i : data)
        scanf("%lf", &i.second.second), i.first = i.second.first / i.second.second;
    sort(data.begin(), data.end(), greater<pair<double, pair<double, double>>>());
    for (auto &i : data) {
        if (i.second.second <= w) {
            w -= i.second.second;
            ans += i.second.first;
        } else {
            ans += i.first * w;
            w = 0;
            break;
        }
    }
    printf("%.4lf\n", ans);
}