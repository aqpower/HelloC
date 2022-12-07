#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int date[maxn];

int main(){
    int i = 0;
    while(cin >> date[i]) i++;
    for (int j = 0; j < i;j++){
        if (date[j] == 250){
            cout << j + 1 ;
            break;
        }
    }

        return 0;
}