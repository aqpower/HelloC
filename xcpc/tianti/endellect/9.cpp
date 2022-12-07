#include <bits/stdc++.h>
using namespace std;
struct per{
    int index, num;
    double sum;
} dat[10005];
bool cmp(per a, per b){
    if(a.sum != b.sum){
        return a.sum > b.sum;
    }
    if(a.num != b.num){
        return a.num > b.num;
    }
    return a.index < b.index;
}
int main(){
    int n, n1,p1;
    cin >> n;
    for (int i = 1; i <= n;i++){
        dat[i].index = i;
        int k;
        cin >> k;
        while(k--){
            cin >> n1 >> p1;
            dat[i].sum -= p1;
            dat[n1].num++;
            dat[n1].sum += p1;
        }
    }
    sort(dat + 1, dat + n + 1, cmp);
    for (int i = 1; i <= n;i++){
        cout << dat[i].index << ' ';
        printf("%.2lf\n", dat[i].sum / 100);
    }

    return 0;
}