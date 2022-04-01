#include <bits/stdc++.h>

template <typename T>
class matrix {
  public:
    std::vector<std::vector<T>> data;

    matrix(int n, int m) {
        data.resize(n);
        for (auto &vec : data)
            vec.resize(m);
    }

    matrix<T> &operator*=(const matrix<T> &rhs) {
        matrix<T> tmp(data.size(), rhs.data[0].size());

        if (this->data[0].size() == rhs.data.size()) {
            for (int c = 0; c < tmp.data.size(); c++)
                for (int c2 = 0; c2 < tmp.data[0].size(); c2++)
                    for (int c3 = 0; c3 < rhs.data.size(); c3++) {
                        tmp.data[c][c2] += this->data[c][c3] * rhs.data[c3][c2];
                    }
        }
        swap(data, tmp.data);
        return *this;
    }

    friend matrix<T> operator*(matrix<T> lhs, const matrix<T> &rhs) {
        lhs *= rhs;

        return lhs;
    }

    matrix<T> &operator%=(const T &rhs) {
        for (auto &row : data)
            for (auto &col : row)
                col %= rhs;
        return *this;
    }

    friend matrix<T> operator%(matrix<T> lhs, const T &rhs) {
        lhs %= rhs;

        return lhs;
    }
};

template <typename T>
T quick_exp(T data, int exp, int mod) {
    if (exp == 1)
        return data;
    else {
        T ret = quick_exp(data, exp / 2, mod) % mod;

        ret *= ret;
        ret %= mod;
        if (exp % 2)
            ret *= data, ret %= mod;
        return ret;
    }
}

int main() {
    int exp, mod;

    scanf("%d%d", &exp, &mod);
    matrix<int> input(2, 2), answer(2, 2);

    for (auto &row : input.data)
        for (auto &col : row)
            scanf("%d", &col);
    answer = quick_exp(input, exp, mod);
    for (auto &row : answer.data)
        for (auto &col : row)
            printf("%d ", col);
    printf("\n");
}