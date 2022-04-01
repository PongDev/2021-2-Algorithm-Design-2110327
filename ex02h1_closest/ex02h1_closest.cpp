#include <bits/stdc++.h>

using namespace std;

int dist(pair<int, int> l, pair<int, int> r) {
    return ((l.first - r.first) * (l.first - r.first)) + ((l.second - r.second) * (l.second - r.second));
}

int closest_pair(int l, int r, vector<pair<int, int>> &xdata, vector<pair<int, int>> &ydata) {
    if (r == l)
        return INT_MAX;
    else if (r - l == 1)
        return dist(xdata[l], xdata[r]);
    int mid = (l + r) / 2;
    vector<int> tmp;
    
    int lmin=closest_pair(l,mid,&xdata,&tmp);
    int rmin;
}

int main() {
    int n;

    scanf("%d", &n);
    vector<pair<int, int>> data(n), ydata;
    for (auto &i : data)
        scanf("%d%d", &i.first, &i.second);
    ydata = data;
    sort(data.begin(), data.end());
    sort(ydata.begin(), ydata.end(), [](pair<int, int> l, pair<int, int> r) {
        return l.second < r.second || (l.second == r.second && l.first < r.first);
    });
    printf("%d\n", closest_pair(0, n - 1, data, ydata));
}