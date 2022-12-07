#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string t;
    string str[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cin >> n;
    while(n--){
        cin >> t;
        bool flag = true;
        for (int i = 0; i < 7;i++){
            if(str[i] == t){
                cout << i + 1 << '\n';
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "-1\n";
        }
    }

    return 0;
}