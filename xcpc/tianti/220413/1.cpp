#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();
    while(n--){
        char t;
        double h;
        scanf("%c %lf", &t, &h);
        getchar();
        if(t == 'M'){
            printf("%.2f\n", h / 1.09);
        } else {
            printf("%.2f\n", h * 1.09);
        }
    }
    return 0;
}