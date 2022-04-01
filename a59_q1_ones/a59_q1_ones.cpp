#include <bits/stdc++.h>

using namespace std;

int findAnswer(int n) {
    static const int baseCase[] = {0, 1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2};
    static const vector<int> one = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

    static auto findDigit = [](int i) {
        int r = 0;

        while (i > 0)
            i /= 10, r += 1;
        return r;
    };
    static auto findFrontDigit = [](int i) {
        while (i > 9)
            i /= 10;
        return i;
    };

    if (n <= 11)
        return baseCase[n];
    auto it = lower_bound(one.begin(), one.end(), n);
    if (*it == n)
        return it - one.begin();

    int digit, frontDigit, r = INT_MAX;

    digit = findDigit(n);
    frontDigit = findFrontDigit(n);
    if (frontDigit == 1 && one[digit - 1] * 9 <= n && n <= one[digit]) {
        if (((digit - 1) * 9) + (n - one[digit - 1] * 9) < digit + (one[digit] - n))
            r = min(r, (digit - 1) + findAnswer(n - one[digit - 1]));
        else
            r = min(r, digit + findAnswer(one[digit] - n));
    } else if (frontDigit == 9 && (one[digit] * 9) <= n && n <= one[digit + 1]) {
        if ((digit * 9) + (n - (one[digit] * 9)) < (digit + 1) + (one[digit + 1] - n))
            r = min(r, (digit * 9) + findAnswer(n - (one[digit] * 9)));
        else
            r = min(r, (digit + 1) + findAnswer(one[digit + 1] - n));
    } else if ((frontDigit - 1) * one[digit] <= n && n <= frontDigit * one[digit]) {
        if (((frontDigit - 1) * digit) + (n - ((frontDigit - 1) * one[digit])) < (frontDigit * digit) + ((frontDigit * one[digit]) - n))
            r = min(r, ((frontDigit - 1) * digit) + findAnswer(n - ((frontDigit - 1) * one[digit])));
        else
            r = min(r, (frontDigit * digit) + findAnswer((frontDigit * one[digit]) - n));
    } else if (frontDigit * one[digit] <= n && n <= (frontDigit + 1) * one[digit]) {
        if ((frontDigit * digit) + (n - (frontDigit * one[digit])) < ((frontDigit + 1) * digit) + (((frontDigit + 1) * one[digit]) - n))
            r = min(r, (frontDigit * digit) + findAnswer(n - (frontDigit * one[digit])));
        else
            r = min(r, ((frontDigit + 1) * digit) + findAnswer(((frontDigit + 1) * one[digit]) - n));
    }
    if (frontDigit * one[digit] != n && abs((frontDigit * one[digit]) - n) != n)
        r = min(r, findAnswer(frontDigit * one[digit]) + findAnswer(abs((frontDigit * one[digit]) - n)));
    return r;
}

int main() {
    int n;

    scanf("%d", &n);
    printf("%d\n", findAnswer(n));
    for (int c = 1; c <= 1111; c++)
        if (abs(findAnswer(c) - findAnswer(c + 1)) > 1 || abs(findAnswer(c) - findAnswer(c - 1)) > 1)
            printf("%d | %d\n", c, findAnswer(c));
}