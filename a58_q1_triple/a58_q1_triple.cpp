#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, target;

    scanf("%d%d", &n, &m);
    vector<int> data(n);
    for (int c = 0; c < n; c++)
        scanf("%d", &data[c]);
    vector<tuple<int, int, int>> sum;
    for (int i = 0; i < data.size(); i++)
        for (int j = i + 1; j < data.size(); j++)
            sum.push_back({data[i] + data[j], i, j});
    sort(sum.begin(), sum.end());
    while (m--) {
        bool isAnswer = false;
        scanf("%d", &target);
        for (int i = 0; i < data.size() && !isAnswer; i++) {
            int left = target - data[i];

            auto it = lower_bound(sum.begin(), sum.end(), make_tuple(left, -1, -1));
            auto end = upper_bound(sum.begin(), sum.end(), make_tuple(left, INT_MAX, INT_MAX));
            while (it != end) {
                if (i != get<1>(*it) && i != get<2>(*it)) {
                    isAnswer = true;
                    break;
                }
                it++;
            }
        }
        printf("%s\n", isAnswer ? "YES" : "NO");
    }
}