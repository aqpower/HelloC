#include <bits/stdc++.h>
using namespace std;
struct BOOK{
    int rh, rm;
}date[1005];

int main(){
    int n;
    cin >> n;
    while(n--){
        int nb,h,m;
        bool vis[1005] = {false};
        vector<int> min;
        int sum = 0;
        char c;
        while(scanf("%d %c %d:%d", &nb, &c, &h, &m),nb!=0){
            if (c == 'S'){
                if(!vis[nb]){
                    vis[nb] = true;
                    date[nb].rh = h;
                    date[nb].rm = m;
                }
            } else {
                if(vis[nb]){
                    vis[nb] = false;
                    sum++;
                    if(m < date[nb].rm){
                        m += 60;
                        h--;
                    }
                    min.push_back((h - date[nb].rh) * 60 + m - date[nb].rm);
                }
            }
        }
        int summ = 0;
        for (int i = 0; i < min.size();i++){
            summ += min[i];
        }
        int ave = 0;
        if(sum){
            ave = summ/sum;
            if(summ%sum){
                ave++;
            }
        }
        cout << sum << ' ' << ave << '\n';
    }

    return 0;
}