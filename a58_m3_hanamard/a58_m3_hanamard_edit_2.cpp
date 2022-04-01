#include <bits/stdc++.h>

using namespace std;

void truncate(vector<vector<int>> &data) {
    for (auto &vec : data) {
        vector<int> tmp;
        for (int c = 0; c < vec.size(); c += 2)
            tmp.push_back(vec[c] + vec[c + 1]);
        vec = tmp;
    }
    if (data[0].size() > 1) {
        int currentSize = data.size();

        for (int c = 0; c < currentSize; c++) {
            data.push_back(data[c]);
            for (int c = 0; c < data.back().size(); c++)
                if (c % 2 == 1)
                    data.back()[c] *= -1;
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);
    if (n == 1) {
        int i;

        scanf("%d", &i);
        printf("%d\n", i);
    } else {
        vector<vector<int>> data(2);
        data[0].resize(n);
        for (auto &i : data[0])
            scanf("%d", &i);
        data[1] = data[0];
        for (int c = 0; c < n; c++)
            if (c % 2)
                data[1][c] *= -1;
        while (data[0].size() != 1)
            truncate(data);
        for (auto &vec : data)
            printf("%d ", vec[0]);
        printf("\n");
    }
}