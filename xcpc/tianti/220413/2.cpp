#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, m;
    scanf("%d:%d", &h, &m);
    if(h >=0 && h <= 12){
        printf("Only %02d:%02d.  Too early to Dang.\n", h, m);
    } else {
        h -= 12;
        if(m){
            h++;
        }
        while(h--){
            cout << "Dang";
        }
        cout << '\n';
    }
    return 0;
}