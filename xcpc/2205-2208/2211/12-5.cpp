#include <cmath>
#include <iostream>
#include <set>
using namespace std;

typedef struct P {

  int a, b, c;
  bool operator<(const struct P &p) const {
    return (this->a < p.a || this->b < p.b || this->c < p.c);
  }
} P;

int Sol(P m, P n) {
  return pow((m.a - n.a), 2) + pow((m.b - n.b), 2) + pow((m.c - n.c), 2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    bool fg = true;
    P p[10];
    set<P> se;
    for (int i = 0; i < 8; i++) {
      cin >> p[i].a >> p[i].b >> p[i].c;
      se.insert(p[i]);
    }
    if (se.size() < 8) {
      cout << "NO" << '\n';
      continue;
    }
    set<int> edg;
    for (int i = 0; i < 8; i++) {
      set<int> equ;
      for (int j = 0; j < 8; j++) {
        if (j == i) {
          continue;
        }
        equ.insert(Sol(p[i], p[j]));
      }
      if (equ.size() != 3) {
        fg = false;
        break;
      }
      edg.insert(*(equ.begin()));
    }
    if (fg && edg.size() == 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
