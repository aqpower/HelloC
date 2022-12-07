#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int y, f;
    for (y = 0; y <= 100;y++){
        for (f = 0; f <= 100;f++){
            if(98 * f - 199 * y - n == 0){
                printf("%d.%02d", y, f);
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}