#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool vis[45] = {false};
    for (int i = 0; i < str.size();i++){
        if(!vis[i]){
            cout << str[i];
            if(isdigit(str[i]) || (str[i-1]=='(' && str[i] == '-')){
                int k = i + 1;
                while(k < str.size() && (isdigit(str[k]) || str[k] == '.')){
                    vis[k] = true;
                    cout << str[k];
                    k++;
                }
            }
            cout << '\n';
        }
    }

        return 0;
}