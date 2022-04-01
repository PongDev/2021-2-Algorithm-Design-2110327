#include <bits/stdc++.h>

using namespace std;

char findG(int n) {
    int now = 1, countA = 2;
    vector<int> gPos;

    while (now <= n) {
        gPos.push_back(now);
        if (now == n)
            return 'g';
        now += countA;
        countA++;
        int rem = gPos.size() - 1;
        for (int c = 0; c < rem; c++) {
            gPos.push_back(gPos[c] + now);
            if (gPos[c] + now == n)
                return 'g';
        }
        now = gPos.back() + 3;
    }
    return 'a';
}

int main() {
    int n;

    scanf("%d", &n);
    printf("%c\n", findG(n));
}