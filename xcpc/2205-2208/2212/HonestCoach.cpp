/*
There are nn athletes in front of you. Athletes are numbered from 11 to nn from
left to right. You know the strength of each athlete — the athlete number ii has
the strength s_is
i

You want to split all athletes into two teams. Each team must have at least one
athlete, and each athlete must be exactly in one team.

You want the strongest athlete from the first team to differ as little as
possible from the weakest athlete from the second team. Formally, you want to
split the athletes into two teams AA and BB so that the value |\max(A) -
\min(B)|∣max(A)−min(B)∣ is as small as possible, where \max(A)max(A) is the
maximum strength of an athlete from team AA, and \min(B)min(B) is the minimum
strength of an athlete from team BB.

For example, if n=5n=5 and the strength of the athletes is s=[3, 1, 2, 6,
4]s=[3,1,2,6,4], then one of the possible split into teams is:

first team: A = [1, 2, 4]A=[1,2,4],
second team: B = [3, 6]B=[3,6].
In this case, the value |\max(A) - \min(B)|∣max(A)−min(B)∣ will be equal to
|4-3|=1∣4−3∣=1. This example illustrates one of the ways of optimal split into
two teams.

Print the minimum value |\max(A) - \min(B)|∣max(A)−min(B)∣.
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 105;
int a[maxn];

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int res = 1e9;
        for (int i = 2; i <= n; i++) {
            res = min(res, abs(a[i] - a[i - 1]));
        }
        cout << res << '\n';
    }
    return 0;
}
