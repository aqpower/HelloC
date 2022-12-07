#include <cstdio>
using namespace std;
const int MAXN = 100000;
bool p[MAXN] = {false};
int prime[MAXN], num = 0;
void find_prime() {
  for (int i = 2; i < MAXN; i++) {
    if (p[i] == false) {
      prime[num++] = i;
      for (int j = i + i; j < MAXN; j += i) p[j] = true;
    }
  }
}

int main() {
  find_prime();
  for (int i = 0; i < num; i++) {
    printf("%d ", prime[i]);
    if (i && i % 10 == 0) putchar('\n');
  }
  return 0;
}