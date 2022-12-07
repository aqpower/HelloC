#include <bits/stdc++.h>
using namespace std;
int live[75];
bool food = false;
int main(){
    int earn = 0;
    fill(live, live + 73, 1);
    string str;
    cin >> str;
    for (int k = 0; k < str.size() - 1;k++){
        char now = str[k];
        int nl = live[k];
        if(now == 'T'){
            if(nl > 0){
                if(!food){
                    earn -= 3;
                } else {
                    food = false;
                }
                live[k + 1]--;
                live[k + 2]--;
                earn += 10;
                cout << 'D';
            } else {
                if(!food){
                    earn -= 3;
                    food = true;
                }
                cout << '-';
            }
        } else if(now == 'C'){
            if(!food){
                earn -= 3;
                food = true;
            }
            if(nl > 0){
                live[k + 1] += 99;
                live[k + 2] += 99;
                food = false;
                cout << '!';
            } else {
                cout << '-';
            }
        } else {
            if(nl > 0){
                live[k + 1]--;
                cout << 'U';
            }else {
                cout << '-';
            }
        }
    }
    if(food){
        earn += 3;
    }
    cout << '\n' << earn;
    return 0;
}