#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int h, m;
        int ans = 0;
        scanf("%d:%d", &h, &m);
        int x;
        cin >> x;
        int nh = h, nm = m;
            switch (nh){
                case 0:
                    if(nm == 0){
                        ans++;
                    }
                    break;
                case 1:
                    if(nm == 10){
                        ans++;
                    }
                    break;
                case 2:
                    if(nm == 20){
                        ans++;
                    }
                    break;
                case 3:
                    if(nm == 30){
                        ans++;
                    }
                    break;
                case 4:
                    if(nm == 40){
                        ans++;
                    }
                    break;
                case 5:
                    if(nm == 50){
                        ans++;
                    }
                    break;
                case 10:
                    if(nm == 1){
                        ans++;
                    }
                    break;
                case 11:
                    if(nm == 11){
                        ans++;
                    }
                    break;
                case 12:
                    if(nm == 21){
                        ans++;
                    }
                    break;
                case 13:
                    if(nm == 31){
                        ans++;
                    }
                    break;
                case 14:
                    if(nm == 41){
                        ans++;
                    }
                    break;
                case 15:
                    if(nm == 51){
                        ans++;
                    }
                    break;
                case 20:
                    if(nm == 2){
                        ans++;
                    }
                    break;
                case 21:
                    if(nm == 12){
                        ans++;
                    }
                    break;
                case 22:
                    if(nm == 22){
                        ans++;
                    }
                    break;
                case 23:
                    if(nm == 32){
                        ans++;
                    }
                    break;
                default:
                    break;
            }
            nm += x;
            while(nm >= 60){
                nm -= 60;
                nh++;
                if(nh > 23){
                    nh = 0;
                }
            }
            while (nm != m || nh != h)
            {
                switch (nh)
                {
                case 0:
                    if(nm == 0){
                        ans++;
                    }
                    break;
                case 1:
                    if(nm == 10){
                        ans++;
                    }
                    break;
                case 2:
                    if(nm == 20){
                        ans++;
                    }
                    break;
                case 3:
                    if(nm == 30){
                        ans++;
                    }
                    break;
                case 4:
                    if(nm == 40){
                        ans++;
                    }
                    break;
                case 5:
                    if(nm == 50){
                        ans++;
                    }
                    break;
                case 10:
                    if(nm == 1){
                        ans++;
                    }
                    break;
                case 11:
                    if(nm == 11){
                        ans++;
                    }
                    break;
                case 12:
                    if(nm == 21){
                        ans++;
                    }
                    break;
                case 13:
                    if(nm == 31){
                        ans++;
                    }
                    break;
                case 14:
                    if(nm == 41){
                        ans++;
                    }
                    break;
                case 15:
                    if(nm == 51){
                        ans++;
                    }
                    break;
                case 20:
                    if(nm == 2){
                        ans++;
                    }
                    break;
                case 21:
                    if(nm == 12){
                        ans++;
                    }
                    break;
                case 22:
                    if(nm == 22){
                        ans++;
                    }
                    break;
                case 23:
                    if(nm == 32){
                        ans++;
                    }
                    break;
                default:
                    break;
            }
            nm += x;
            while(nm >= 60){
                nm -= 60;
                nh++;
                if(nh > 23){
                    nh = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}