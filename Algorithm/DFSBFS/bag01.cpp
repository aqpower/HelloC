#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
int n, v, w[MAXN], c[MAXN], maxvalue = 0;
void DFS(int index, int sumW, int sumC){
    if (sumW > v){
        return;
    }
    if (index  == n){
        if (sumC > maxvalue){
            maxvalue = sumC;
        }
    }
    else{
        DFS(index + 1, sumW, sumC);
        DFS(index + 1, sumW + w[index], sumC + c[index]);
    }
}
int main()
{
    cin >> n >> v;
    for (int i = 0; i < n; i++){
        cin >> w[i] >> c[i];
    }
    DFS(0, 0, 0);
    cout << maxvalue << '\n';

    return 0;
}