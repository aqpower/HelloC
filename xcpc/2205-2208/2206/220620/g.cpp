#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, now = 0, pre = 0, dx = -1;
        cin >> w >> h;
        int k;
        cin >> k;
        for (int i = 0; i < k;i++){
            if(i){
                pre = now;
            } 
            cin >> now;
            dx = max(dx, now - pre);
        }
    }
    
}