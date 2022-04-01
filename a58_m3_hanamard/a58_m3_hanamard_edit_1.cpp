#include <bits/stdc++.h>

using namespace std;

void generateAnswer(vector<int> &data, vector<int> &answer, int x1, int y1, int x2, int y2, bool isMinus) {
    if (x2 - x1 == 1)
        answer[x1] += data[y1] * (isMinus ? -1 : 1);
    else if (x2 - x1 == 2) {
        answer[x1] += data[y1] * (isMinus ? -1 : 1);
        answer[x1 + 1] += data[y1] * (isMinus ? -1 : 1);
        answer[x1] += data[y1 + 1] * (isMinus ? -1 : 1);
        answer[x1 + 1] -= data[y1 + 1] * (isMinus ? -1 : 1);
    } else {
        int len = (x2 - x1) / 2;
        generateAnswer(data, answer, x1, y1, x1 + len, y1 + len, isMinus);
        generateAnswer(data, answer, x1, y1 + len, x1 + len, y2, isMinus);
        generateAnswer(data, answer, x1 + len, y1, x2, y1 + len, isMinus);
        generateAnswer(data, answer, x1 + len, y1 + len, x2, y2, !isMinus);
    }
}

int main() {
    int n, i;

    scanf("%d", &n);
    vector<int> data(n);
    for (auto &i : data)
        scanf("%d", &i);
    vector<int> answer(n);
    generateAnswer(data, answer, 0, 0, n, n, false);
    for (auto &i : answer)
        printf("%d ", i);
    printf("\n");
}