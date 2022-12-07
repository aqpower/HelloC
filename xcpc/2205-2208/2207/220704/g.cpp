#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    int n;
    while (t--){
        cin >> n;
        if (n == 1){
            cout << 1 << endl;
        }
        else if (n == 2){
            cout << -1 << endl;
        }
        else {
            int step = 0;
            for (int i = 1; i <= n * n; i += 2){
                cout << i << " ";
                step++;
                if(step == n){
                    cout << '\n';
                    step = 0;
                }
            }
            for (int i = 2; i <= n * n; i += 2){
                cout << i << " ";
                step++;
                if(step == n){
                    cout << '\n';
                    step = 0;
                }
            }
        }
    }
    return 0;
}