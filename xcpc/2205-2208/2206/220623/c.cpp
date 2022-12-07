#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, t, num, ans = 0, mao = 0;
        cin >> n >> num;
        int dat[n + 5];
        memset(dat, 0, sizeof(dat));
        priority_queue<int> pq;
        for (int i = 1; i <= num;i++){
            cin >> t;
            dat[t]++;
            pq.push(t);
        }
        while(num && (!pq.empty())){
            int ind = pq.top();
            pq.pop();
            dat[ind] -= 1;
            dat[ind + 1] += 1;
            if(ind + 1 == n){
                num--;
                ans++;
            } else {
                pq.push(ind + 1);
            }
            mao++;
            num -= dat[mao];
            dat[mao] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}