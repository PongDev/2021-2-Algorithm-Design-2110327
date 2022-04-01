#include <bits/stdc++.h>

using namespace std;

void findAns(vector<tuple<int, int, int>> &ans, int x1, int y1, int x2, int y2, int tx, int ty) {
    if (x2 - x1 == 1 && y2 - y1 == 1) {
        tx -= x1;
        ty -= y1;
        if (tx == 0 && ty == 0) {
            ans.push_back({0, x1, y1});
        } else if (tx == 0 && ty == 1) {
            ans.push_back({2, x1, y1});
        } else if (tx == 1 && ty == 0) {
            ans.push_back({1, x1, y1});
        } else if (tx == 1 && ty == 1) {
            ans.push_back({3, x1, y1});
        }
    } else {
        int half = (x2 - x1 + 1) / 2;

        if (x1 <= tx && tx <= x1 + half - 1 && y1 <= ty && ty <= y1 + half - 1) {
            findAns(ans, x1, y1, x1 + half - 1, y1 + half - 1, tx, ty);
            findAns(ans, x1 + half, y1, x2, y1 + half - 1, x1 + half, y1 + half - 1);
            findAns(ans, x1, y1 + half, x1 + half - 1, y2, x1 + half - 1, y1 + half);
            findAns(ans, x1 + half, y1 + half, x2, y2, x1 + half, y1 + half);
            ans.push_back({0, x1 + half - 1, y1 + half - 1});
        } else if (x1 + half <= tx && tx <= x2 && y1 <= ty && ty <= y1 + half - 1) {
            findAns(ans, x1, y1, x1 + half - 1, y1 + half - 1, x1 + half - 1, y1 + half - 1);
            findAns(ans, x1 + half, y1, x2, y1 + half - 1, tx, ty);
            findAns(ans, x1, y1 + half, x1 + half - 1, y2, x1 + half - 1, y1 + half);
            findAns(ans, x1 + half, y1 + half, x2, y2, x1 + half, y1 + half);
            ans.push_back({1, x1 + half - 1, y1 + half - 1});
        } else if (x1 <= tx && tx <= x1 + half - 1 && y1 + half <= ty && ty <= y2) {
            findAns(ans, x1, y1, x1 + half - 1, y1 + half - 1, x1 + half - 1, y1 + half - 1);
            findAns(ans, x1 + half, y1, x2, y1 + half - 1, x1 + half, y1 + half - 1);
            findAns(ans, x1, y1 + half, x1 + half - 1, y2, tx, ty);
            findAns(ans, x1 + half, y1 + half, x2, y2, x1 + half, y1 + half);
            ans.push_back({2, x1 + half - 1, y1 + half - 1});
        } else if (x1 + half <= tx && tx <= x2 && y1 + half <= ty && ty <= y2) {
            findAns(ans, x1, y1, x1 + half - 1, y1 + half - 1, x1 + half - 1, y1 + half - 1);
            findAns(ans, x1 + half, y1, x2, y1 + half - 1, x1 + half, y1 + half - 1);
            findAns(ans, x1, y1 + half, x1 + half - 1, y2, x1 + half - 1, y1 + half);
            findAns(ans, x1 + half, y1 + half, x2, y2, tx, ty);
            ans.push_back({3, x1 + half - 1, y1 + half - 1});
        }
    }
}

int main() {
    int l, x, y;
    vector<tuple<int, int, int>> ans;

    scanf("%d%d%d", &l, &x, &y);
    findAns(ans, 0, 0, l - 1, l - 1, x, y);
    printf("%d\n", ans.size());
    for (auto i : ans)
        printf("%d %d %d\n", get<0>(i), get<1>(i), get<2>(i));
}