#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    vector<int> ans,va,vb;
    getline(cin, a);
    getline(cin, b);
    int now = 0;
    for (int i = 0; i < a.size();i++){
        if(isdigit(a[i]) || (a[i] == '-'&&(isdigit(a[i+1])))){
            string aa;
            aa += a[i++];
            while(i<a.size() && isdigit(a[i])){
                aa += a[i++];
            }
            int c = stoi(aa);
            va.push_back(c);
        }
    }
    for (int i = 0; i < b.size();i++){
        if(isdigit(b[i]) || (b[i] == '-' && isdigit(b[i+1]) ) ){
            string bb;
            bb += b[i++];
            while(i<b.size() &&isdigit(b[i])){
                bb += b[i++];
            }
            int c = stoi(bb);
            vb.push_back(c);
        }
    }
    int ia = 0, ib = 0;
    for (; ia != va.size() && ib != vb.size();){
        if(va[ia] <= vb[ib]){
            ans.push_back(va[ia++]);
        } else {
            ans.push_back(vb[ib++]);
        }
    }
    if(ia != va.size()){
        for (;ia<va.size();ia++){
            ans.push_back(va[ia]);
        }
    }
    if(ib != vb.size()){
        for (;ib<vb.size();ib++){
            ans.push_back(vb[ib]);
        }
    }
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << "->";
    }
    cout << "NULL";

    return 0;
}