#include <bits/stdc++.h>
using namespace std;
int n, k, dk = 0;
bool pre[10005];
int main(){
    cin >> n >> k;
    //fill(pre, pre + 10005, true);
    for (int i = 0; i < 10005;i++){
        pre[i] = true;
    }
        for (int i = 2; i < 10005; i++)
        {
            if (pre[i])
            {
                for (int j = 2; j * i < 10005; j++)
                {
                    pre[j * i] = false;
                }
            }
        }


    // vector<int> ans;
    // int sum = 0;
    // while(true){
    //     if(pre[n]){
    //         ans.push_back(n);
    //         n--;
    //         dk++;
    //         sum += n;
    //     }
    //     if(dk == k)
    //     {
    //         break;
    //     }
    // }
    // for (int i = 0; i < ans.size();i++){
    //     cout << ans[i];
    //     if(i < ans.size() - 1){
    //         cout << '+';
    //     }else {
    //         cout << '=';
    //     }
    // }
    // cout << sum;
    return 0;
}