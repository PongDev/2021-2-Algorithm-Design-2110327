#include <bits/stdc++.h>

using namespace std;

int findAnswer(int n) {
    static const int baseCase[] = {0, 1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2};
    static const vector<int> ones = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

    if (n <= 11)
        return baseCase[n];
    else {
        auto it = upper_bound(ones.begin(), ones.end(), n);
        auto it2 = it;
        it--;
        return min(((n / (*it)) * (it - ones.begin())) + findAnswer(n % (*it)), ((*it2) - n) < n ? ((it2 - ones.begin()) + findAnswer((*it2) - n)) : INT_MAX);
    }
}

int main() {
    int n;

    scanf("%d", &n);
    printf("%d\n", findAnswer(n));
}