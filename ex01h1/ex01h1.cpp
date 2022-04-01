#include <bits/stdc++.h>

using namespace std;

int findAnswer(int i) {
    static vector<int> ans = {0, 1, 3};
    static int idx = 3;

    while (true) {
        if (!ans.empty() && ans.back() >= i) {
            return lower_bound(ans.begin(), ans.end(), i) - ans.begin();
        }
        auto it = lower_bound(ans.begin(), ans.end(), idx);
        ans.push_back(ans.back() + (it - ans.begin()));
        idx++;
    }
}

int main() {
    int q, i;

    scanf("%d", &q);
    while (q--) {
        scanf("%d", &i);
        printf("%d\n", findAnswer(i));
    }
}