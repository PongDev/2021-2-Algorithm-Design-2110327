#include <bits/stdc++.h>

using namespace std;

void generate(vector<vector<int>> &data, int a, int b, int x1, int y1, int x2, int y2) {
    if (a == 0)
        data[x1][y1] = b;
    else {
        int mid = 1 << (a - 1);
        generate(data, a - 1, b, x1, y1, x1 + mid, y1 + mid);
        generate(data, a - 1, b - 1, x1, y1 + mid, x1 + mid, y1);
        generate(data, a - 1, b + 1, x1 + mid, y1, x2, y1 + mid);
        generate(data, a - 1, b, x1 + mid, y1 + mid, x2, y2);
    }
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    vector<vector<int>> data(1 << a);
    for (auto &vec : data)
        vec.resize(1 << a);
    generate(data, a, b, 0, 0, 1 << a, 1 << a);
    for (auto &vec : data) {
        for (auto &i : vec)
            printf("%d ", i);
        printf("\n");
    }
}