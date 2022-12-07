#include <bits/stdc++.h>
using namespace std;

class test{
    public:
        test(int _a, int _b): a(_a),b(_b){
            cout << "congratulations" << '\n';
        }
        test(){}
        test(test & t){
            cout << "yinyong!" << '\n';
        }
        ~test(){
            cout << "Goodbye" << '\n';
        }
        void set(int aa = 0,int bb = 0){
            a = aa, b = bb;
        }
        int geta(){
            return a;
        }
        int getb(){
            return b;
        }
        int b;
    private:
        int a;
};

int main(){
    test a(5,6);
    // a.set(3, 5);
    test b = a;
    cout << a.b;
    
    cout << a.geta() << '\n';
    cout << b.getb() << '\n';
    return 0;
}