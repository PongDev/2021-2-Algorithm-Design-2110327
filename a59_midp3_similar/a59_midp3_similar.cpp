#include <bits/stdc++.h>

using namespace std;

bool isMatch(string &a, int l1, int r1, string &b, int l2, int r2) {
    bool isEqual = true;

    for (int c = 0; c < (r1 - l1); c++) {
        if (a[l1 + c] != b[l2 + c]) {
            isEqual = false;
            break;
        }
    }
    if (isEqual)
        return true;
    else if (r1 - l1 == 1) {
        return false;
    } else {
        return (isMatch(a, l1, l1 + ((r1 - l1) / 2), b, l2 + ((r2 - l2) / 2), r2) && isMatch(a, l1 + ((r1 - l1) / 2), r1, b, l2, l2 + ((r2 - l2) / 2))) || (isMatch(a, l1, l1 + ((r1 - l1) / 2), b, l2, l2 + ((r2 - l2) / 2)) && isMatch(a, l1 + ((r1 - l1) / 2), r1, b, l2 + ((r2 - l2) / 2), r2));
    }
}

int main() {
    string a, b;

    cin >> a >> b;
    if (a.size() == b.size())
        printf("%s\n", isMatch(a, 0, a.size(), b, 0, b.size()) ? "YES" : "NO");
    else
        printf("NO\n");
}