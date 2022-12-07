#include "stdio.h"

int BOTTOM_UP_CUT_ROD(int *p, int n);
int max(int a, int b);
int MEMOIZED_CUT_ROD(int *p, int n);
int MEMOIZED_CUT_ROD_AUX(int *p, int n, int *r);

int main(){
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    int n = 9;

    int optimal_solution = BOTTOM_UP_CUT_ROD(p, n);

    printf("%d\n", optimal_solution);

    int memorize = MEMOIZED_CUT_ROD(p, n);
    printf("%d\n", memorize);

    return 0;
}

int BOTTOM_UP_CUT_ROD(int *p, int n){
    int r[n + 1];
    r[0] = 0;

    for (int j = 1; j <= n; j++){
        int q = -1;
        for (int i = 1; i <= j; i++){
            q = max(q, p[i] + r[j - i]);
        } 
        r[j] = q;
    }
    return r[n];
}


int MEMOIZED_CUT_ROD(int *p, int n){
    int r[n + 1];
    for (int i = 0; i <= n; i++)
        r[i] = -1;
    return MEMOIZED_CUT_ROD_AUX(p, n, r);
}

int MEMOIZED_CUT_ROD_AUX(int *p, int n, int *r){
    if (r[n] >= 0){
        return r[n];
    }
    int q;
    if (n == 0)
        q = 0;
    else{
        q = -1;
        for (int i = 1; i <= n; i++){
            q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}
int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}