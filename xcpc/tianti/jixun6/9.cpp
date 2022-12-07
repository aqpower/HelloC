#include <bits/stdc++.h>
using namespace std;
int n, l, h;
struct exam{
    int num;
    int de;
    int cai;
    int sum;
};
int ans = 0;
vector<exam> a, de, de2, guo;
bool cmp(exam a,exam b){
    if(a.sum!=b.sum){
        return a.sum > b.sum;
    }
    if(a.de != b.de){
        return a.de > b.de;
    }
    return a.num < b.num;
}

void myprint(vector<exam> a){
    for (int i = 0; i < a.size();i++){
        cout << a[i].num << ' ' << a[i].de << ' ' << a[i].cai << '\n';
    }
}
int main(){
    cin >> n >> l >> h;
    exam t;
    for (int i = 0; i < n;i++){
        cin >> t.num >> t.de >> t.cai;
        t.sum = t.de + t.cai;
        if(t.de < l || t.cai < l){
            continue;
        }
        ans++;
        if(t.de >= h && t.cai >= h){
            a.push_back(t);
        } else if (t.de >= h) {
            de.push_back(t);
        } else if(t.de >= t.cai) {
            de2.push_back(t);
        } else {
            guo.push_back(t);
        }
    }
    sort(a.begin(), a.end(), cmp);
    sort(de.begin(), de.end(), cmp);
    sort(de2.begin(), de2.end(), cmp);
    sort(guo.begin(), guo.end(), cmp);
    cout << ans << '\n';
    myprint(a);
    myprint(de);
    myprint(de2);
    myprint(guo);

    return 0;
}