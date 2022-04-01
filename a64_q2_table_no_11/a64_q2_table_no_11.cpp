#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Matrix {
  private:
    vector<vector<T>> data;

  public:
    Matrix(int n, int m) {
        data.resize(n);
        for (auto &vec : data)
            vec.resize(m);
    }

    vector<T> &operator[](int row) {
        return data[row];
    }

    Matrix<T> &operator*=(const Matrix<T> &rhs) {
        if (this->col() == rhs.row()) {
            vector<vector<T>> tmp(this->row());

            for (auto &vec : tmp)
                vec.resize(rhs.col());
            for (size_t c = 0; c < this->row(); c++)
                for (size_t c2 = 0; c2 < rhs.col(); c2++)
                    for (size_t c3 = 0; c3 < this->col(); c3++)
                        tmp[c][c2] += data[c][c3] * rhs.data[c3][c2];
            swap(data, tmp);
        }
        return *this;
    }

    Matrix<T> &operator%=(const T &mod) {
        for (auto &vec : data)
            for (auto &i : vec)
                i %= mod;
        return *this;
    }

    friend Matrix<T> operator*(Matrix<T> lhs, const Matrix<T> &rhs) {
        return lhs *= rhs;
    }

    friend Matrix<T> operator%(Matrix<T> lhs, const T &rhs) {
        return lhs %= rhs;
    }

    T sum() {
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
T fastExpo(T data, unsigned long long e, unsigned long long mod) {
    if (e < 2)
        return data;
    T r = fastExpo(data, e / 2, mod) % mod;
    r *= r;
    r %= mod;
    if (e % 2) {
        r *= data;
        r %= mod;
    }
    return r;
}

int main() {
    int n;
    const unsigned long long mod = 100000007;
    Matrix<unsigned long long> baseMatrix(1, 3), expoMatrix(3, 3);

    scanf("%d", &n);
    baseMatrix[0][0] = 1;
    baseMatrix[0][1] = 1;
    baseMatrix[0][2] = 1;
    expoMatrix[0][0] = 1;
    expoMatrix[0][1] = 1;
    expoMatrix[0][2] = 1;
    expoMatrix[1][0] = 1;
    expoMatrix[1][1] = 0;
    expoMatrix[1][2] = 1;
    expoMatrix[2][0] = 1;
    expoMatrix[2][1] = 1;
    expoMatrix[2][2] = 0;
    if (n == 1)
        printf("%llu\n", baseMatrix.sum());
    else
        printf("%llu\n", (baseMatrix * fastExpo(expoMatrix, n - 1, mod)).sum() % mod);
}