#include <bits/stdc++.h>
int fact(int n);
int main(void)
{
    double n, s = 0;
    printf("Enter n:\n");
    scanf_s("%lf", &n);
    for (int i = 1; i <= n; i++)
    {
        s += fact(i);
    }
    printf("%.0f\n", s);
    return 0;
}
// double fact(int n){
//     int i;
//     double product = 1;
//     for (i = 1; i <= n; i++)
//     {
//         product *= i;
//     }
//     std::cout << product << '\n';
//     return product;
// }

int fact(int n){
    return n == 1 ? n : n * fact(n - 1);
}