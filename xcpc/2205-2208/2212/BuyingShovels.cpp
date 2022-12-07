#include <iostream>
#include <cmath>
#define INF 1 << 30

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, rst = INF; // rst用来记录“A÷C的结果D”的最小值
        cin >> n >> k;
        for (int i = 1; i * i <= n;
             i++) { // 枚举因子时一次能找到一对，i的枚举范围可以缩小到
                    // i * i <= n
            if (n % i == 0) {                  // 如果n被i整除
                int a = i, b = n / i;          // i与n/i是n的一对因子
                if (a <= k) rst = min(rst, b); // 更新最小值rst
                if (b <= k) rst = min(rst, a); // 更新最小值rst
            }
        }
        cout << rst << endl;
    }
    return 0;
}
