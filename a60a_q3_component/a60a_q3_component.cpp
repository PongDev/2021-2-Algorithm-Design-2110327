#include <bits/stdc++.h>

class UnionFind {
private:
  std::vector<int> p;
  int comp;

public:
  UnionFind(int node) : p(node), comp(node) {
    for (int c = 0; c < node; c++)
      p[c] = c;
  }

  int f(int node) { return p[node] == node ? node : p[node] = f(p[node]); }

  void uni(int x, int y) {
    if (f(x) != f(y)) {
      p[f(x)] = f(y);
      comp--;
    }
  }

  int getComponent() {
      return comp;
  }
};

int main() {
  int n, m, u, v;

  scanf("%d%d", &n, &m);
  UnionFind uf(n);
  for (int c = 0; c < m; c++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    uf.uni(u, v);
  }
  printf("%d\n", uf.getComponent());
}