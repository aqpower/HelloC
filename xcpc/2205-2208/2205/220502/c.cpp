#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    getchar();
    for (int k = 1; k <= t;k++){
        string a,b;
        getline(cin, a);
        getline(cin, b);
        vector<int> sa, sb;
        for (int i = 0; i < a.size();i++){
            if(a[i] != ' '){
                if(a[i] >= 'a'){
                    a[i] -= 32;
                }
                sa.push_back((int)a[i]);
            }
        }
        for (int i = 0; i < b.size();i++){
            if(b[i] != ' '){
                if(b[i] >= 'a'){
                    b[i] -= 32;
                }
                sb.push_back((int)b[i]);
            }
        }
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        printf("Case %d: ", k);
        if(sa == sb){
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << '\n';
    }
    return 0;
}