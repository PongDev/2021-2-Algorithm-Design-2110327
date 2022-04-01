#include <bits/stdc++.h>

using namespace std;

void generateMatrix(vector<vector<int>> &data, int x1, int y1, int x2, int y2) {
    if (x2 - x1 == 1)
        data[x1][y1] = 1;
    else if (x2 - x1 == 2) {
        data[x1][y1] = 1;
        data[x1 + 1][y1] = 1;
        data[x1][y1 + 1] = 1;
        data[x1 + 1][y1 + 1] = -1;
    } else {
        int len = (x2 - x1) / 2;
        generateMatrix(data, x1, y1, x1 + len, y1 + len);
        generateMatrix(data, x1, y1 + len, x1 + len, y2);
        generateMatrix(data, x1 + len, y1, x2, y1 + len);
        generateMatrix(data, x1 + len, y1 + len, x2, y2);
        for (int c = x1 + len; c < x2; c++)
            for (int c2 = y1 + len; c2 < y2; c2++)
                data[c][c2] *= -1;
    }
}

int main() {
    int n, i;

    scanf("%d", &n);
    vector<vector<int>> matrix(n);
    for (auto &vec : matrix)
        vec.resize(n);
    generateMatrix(matrix, 0, 0, n, n);
    for (auto &vec : matrix) {
        for (auto &i : vec)
            printf("[%c] ", i == 1 ? 'O' : ' ');
        printf("\n");
    }
}