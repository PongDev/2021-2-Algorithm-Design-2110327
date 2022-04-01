#include <bits/stdc++.h>

using namespace std;

void processAnswer(const vector<vector<int>> &gph, vector<int> &inDegree, vector<bool> &isUsed, vector<int> &answer, int lv, const int &n) {
    if (lv == n) {
        for (auto &i : answer)
            printf("%d ", i);
        printf("\n");
    } else {
        for (int c = 0; c < n; c++)
            if (!isUsed[c] && inDegree[c] == 0) {
                answer[lv] = c;
                for (auto &i : gph[c])
                    inDegree[i]--;
                isUsed[c] = true;
                processAnswer(gph, inDegree, isUsed, answer, lv + 1, n);
                isUsed[c] = false;
                for (auto &i : gph[c])
                    inDegree[i]++;
            }
    }
}

int main() {
    int n, m, u, v;

    scanf("%d%d", &n, &m);
    vector<vector<int>> gph(n);
    vector<int> inDegree(n), answer(n);
    vector<bool> isUsed(n);
    for (int c = 0; c < m; c++) {
        scanf("%d%d", &u, &v);
        gph[u].push_back(v);
        inDegree[v]++;
    }
    processAnswer(gph, inDegree, isUsed, answer, 0, n);
}