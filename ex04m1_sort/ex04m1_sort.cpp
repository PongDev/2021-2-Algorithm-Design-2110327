#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    queue<int> pos[4][4];

    scanf("%d", &n);
    vector<int> data(n), sortData;
    for (auto &i : data)
        scanf("%d", &i);
    sortData = data;
    sort(sortData.begin(), sortData.end());
    for (size_t c = 0; c < data.size(); c++) {
        if (data[c] != sortData[c])
            pos[data[c]][sortData[c]].push(c);
    }
    for (int c = 1; c <= 3; c++)
        for (int c2 = c + 1; c2 <= 3; c2++)
            if (!pos[c][c2].empty() && !pos[c2][c].empty()) {
                swap(data[pos[c][c2].front()], data[pos[c2][c].front()]);
                pos[c][c2].pop();
                pos[c2][c].pop();
                ans++;
            }
    for (size_t c = 0; c < data.size(); c++) {
        if (data[c] != sortData[c]) {
            for (size_t c2 = 1; c2 <= 3; c2++)
                if (sortData[c] != c2) {
                    while (!pos[sortData[c]][c2].empty() && data[pos[sortData[c]][c2].front()] != sortData[c])
                        pos[sortData[c]][c2].pop();
                    if (!pos[sortData[c]][c2].empty()) {
                        swap(data[c], data[pos[sortData[c]][c2].front()]);
                        pos[sortData[c]][c2].pop();
                        ans++;
                        break;
                    }
                }
        }
    }
    printf("%d\n", ans);
}
