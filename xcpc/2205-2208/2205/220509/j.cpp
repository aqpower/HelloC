#include <bits/stdc++.h>
using namespace std;
int dat[(int)1e5 + 5];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &dat[i]);
    }
    int m;
    scanf("%d", &m);
    while(m--){
        int t;
        scanf("%d", &t);
        int l = 0, r = n - 1;
        int mid;
        bool flag = false;
        while(l <= r){
            mid = (l + r) / 2;
            if(dat[mid] == t){
                flag = true;
                break;
            } else if(dat[mid] > t){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(!flag){
            if(l == n){
                l--;
            }
            if(r == -1){
                r++;
            }
            int dl = abs(dat[l] - t);
            int dr = abs(dat[r] - t);
            if(dl == dr){
                cout << dat[r] << '\n';
            } else if(dl > dr){
                cout << dat[r] << '\n';
            } else {
                cout << dat[l] << '\n';
            }
        } else {
            cout << dat[mid] << '\n';
        }
    }
    return 0;
}
