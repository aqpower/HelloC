#include <stdio.h>

int main(){
    int a[20], sum = 0;
    for (int i = 0; i < 18;i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%d %.2lf\n", sum, 1.0 * sum / 18);
    return 0;
}