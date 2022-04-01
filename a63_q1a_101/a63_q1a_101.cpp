#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Matrix {
  private:
    vector<vector<T>> data;

  public:
    Matrix(size_t row, size_t col) {
        data.resize(row);
        for (auto &vec : data)
            vec.resize(col);
    }

    Matrix<T> &operator*=(const Matrix<T> &rhs) {
        if (this->col() == rhs.row()) {
            vector<vector<T>> ret;
            ret.resize(this->row());
            for (auto &vec : ret)
                vec.resize(rhs.col());
            for (size_t r = 0; r < this->row(); r++)
                for (size_t c = 0; c < rhs.col(); c++)
                    for (size_t i = 0; i < this->col(); i++)
                        ret[r][c] += data[r][i] * rhs.data[i][c];
            swap(data, ret);
        }
        return *this;
    }

    friend Matrix<T> operator*(Matrix<T> lhs, const Matrix<T> &rhs) {
        return lhs *= rhs;
    }

    Matrix<T> &operator%=(T mod) {
        for (auto &vec : data)
            for (auto &i : vec)
                i %= mod;
        return *this;
    }

    friend Matrix<T> operator%(Matrix<T> lhs, T rhs) {
        return lhs %= rhs;
    }

    vector<T> &operator[](const size_t &idx) {
        return data[idx];
    }

    T sum() const {
        T r = 0;

        for (auto &vec : data)
            for (auto &i : vec)
                r += i;
        return r;
    }

    size_t row() const {
        return data.size();
    }

    size_t col() const {
        return data[0].size();
    }
};

template <typename T>
T exponential(T data, unsigned long long e, unsigned long long mod) {
    if (e == 1)
        return data %= mod;
    T r = exponential(data, e / 2, mod) % mod;
    r *= r;
    r %= mod;
    if (e % 2) {
        r *= data;
        r %= mod;
    }
    return r;
}

int main() {
    unsigned long long n;
    unsigned long long mod = 100000007;
    Matrix<long long> baseMatrix(1, 4), expoMatrix(4, 4);

    baseMatrix[0][0] = 2;
    baseMatrix[0][1] = 2;
    baseMatrix[0][2] = 1;
    baseMatrix[0][3] = 2;
    expoMatrix[0][0] = 1;
    expoMatrix[0][1] = 0;
    expoMatrix[0][2] = 1;
    expoMatrix[0][3] = 0;
    expoMatrix[1][0] = 1;
    expoMatrix[1][1] = 0;
    expoMatrix[1][2] = 0;
    expoMatrix[1][3] = 0;
    expoMatrix[2][0] = 0;
    expoMatrix[2][1] = 1;
    expoMatrix[2][2] = 0;
    expoMatrix[2][3] = 1;
    expoMatrix[3][0] = 0;
    expoMatrix[3][1] = 1;
    expoMatrix[3][2] = 0;
    expoMatrix[3][3] = 1;

    scanf("%llu", &n);
    n -= 3;
    if (n == 0)
        printf("%lld\n", baseMatrix.sum() % mod);
    else
        printf("%lld\n", (baseMatrix * exponential(expoMatrix, n, mod)).sum() % mod);
}