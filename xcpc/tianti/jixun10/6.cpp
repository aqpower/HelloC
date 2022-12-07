#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    getchar();
    while(n--){
        string s;
        cin >> s;
        getchar();
        int sumf = 0, suml = 0;
        for (int i = 0; i < 3;i++){
            sumf += s[i] - '0';
        }
        for (int i = 3; i < 6;i++){
            suml += s[i] - '0';
        }
        if(sumf == suml){
            cout << "You are lucky!" << '\n';
        } else {
            cout << "Wish you good luck." << '\n';
        }
    }

    return 0;
}