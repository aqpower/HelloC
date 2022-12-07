#include <bits/stdc++.h>
using namespace std;
struct node{
    int l, r;
} a[150];//65
vector<int> ans;
void midfir(int n){
    if(a[n].l != -1){
        midfir(a[n].l);
    }
    ans.push_back(n);
    if(a[n].r != -1){
        midfir(a[n].r);
    }
}
int main(){
    int num,fa;
    char y;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size();i++){
        if(isalpha(s[i])){
            string ts;
            int now = s[i] - 65;
            a[now].l = -1;
            a[now].r = -1;
            i += 2;
            y = s[i];
            i+=2;
            while(isdigit(s[i])){
                ts += s[i++];
            }
            num = stoi(ts);
            if(y == '0'){
                fa = now;
            } else {
                if(num == 1){
                    a[y - 65].l = now;
                } else {
                    a[y - 65].r = now;
                }
            }
        }
    }
    midfir(fa);
    for(int i = 0; i < ans.size();i++){
        cout << (char)(ans[i]+65);
        if(i != ans.size() - 1){
            cout << ' ';
        }
    }
    return 0;
}