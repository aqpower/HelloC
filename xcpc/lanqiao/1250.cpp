#include <bits/stdc++.h>
using namespace std;
struct myans{
    int a, b, c;
    myans(int _a, int _b, int _c):a(_a),b(_b), c(_c){}
};
int main(){
    int n;
    int a, b, c;
    while(std::cin >> n){
        vector<myans> ans;
        for (int a = 1;a <= sqrt(n);a++){
            for (int b = a; b <= sqrt(n);b++){
                for (int c = b; c <= sqrt(n);c++){
                    if(a*a + b*b + c*c == n){
                        ans.push_back(myans(a, b, c));
                    }
                }
            }
        }
        if(ans.empty()){
            cout << "No Solution" << '\n';
        } else {
            for (int i = 0; i < ans.size();i++){
                cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << '\n';
            }
        }
    }

    return 0;
}