#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, i, ans = INT_MIN, sz = 0, sum = 0;
    deque<pair<int, int>> q;

    scanf("%d%d", &n, &w);
    for (int c = 0; c < n; c++) {
        scanf("%d", &i);
        ans = max(ans, i);
        pair<int, int> tmp = {i, 1};
        while (!q.empty() && tmp.first <= 0 && q.back().first + tmp.first <= 0) {
            tmp.first += q.back().first;
            tmp.second += q.back().second;
            q.pop_back();
        }
        q.push_back({tmp.first, tmp.second});
        sum += i;
        sz += 1;
        while (sz > w || (!q.empty() && q.front().first <= 0)) {
            sum -= q.front().first;
            sz -= q.front().second;
            q.pop_front();
        }
        if (!q.empty())
            ans = max(ans, sum);
    }
    printf("%d\n", ans);
}