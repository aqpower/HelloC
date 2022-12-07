#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, na, nb, sa = 0, sb = 0;
    list<int> a, b;
    cin >> n >> na >> nb;
    for (int i = 0; i < na;i++){
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < nb;i++){
        cin >> t;
        b.push_back(t);
    }
    auto da = a.begin(), db = b.begin();
    while(n--){
        int nowa = *da, nowb = *db;
        da++, db++;
        if(nowa == nowb){
            continue;
        }
        if(nowa == 0){
            if(nowb == 2 || nowb == 3){
                sa++;
            } else if(nowb == 1 || nowb == 4){
                sb++;
            } 
        } else if(nowa == 1){
            if(nowb == 3 || nowb == 4){
                sa++;
            } else if(nowb == 0 || nowb == 2){
                sb++;
            } 
        } else if(nowa == 2){
            if(nowb == 1 || nowb == 4){
                sa++;
            } else if(nowb == 3 || nowb == 0){
                sb++;
            } 
        } else if(nowa == 3){
            if(nowb == 2 || nowb == 4){
                sa++;
            } else if(nowb == 1 || nowb == 0){
                sb++;
            } 
        } else {
            if(nowb == 0 || nowb == 1){
                sa++;
            } else if(nowb == 2 || nowb == 3){
                sb++;
            } 
        }
    }
    cout << sa << ' ' << sb;
    
    return 0;
}