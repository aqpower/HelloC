#include <bits/stdc++.h>
using namespace std;
class A{
    public:
         void show() { cout << "showA" << endl; }
        virtual void printA() { cout << "printA" << endl; }
};
class B:public A{
    public:
        void show() { cout << "showB" << endl; }
        void printB() { cout << "printB" << endl; }
};
void f(A *p){
    p->show();
    p->printA();
    // p->printB();
}
int main(){
    A a;
    B b;
    f(&a);
    f(&b);
    return 0;
}
