#include <iostream>
using namespace std;
class Myclass {
public:
    Myclass(int, int);
    Myclass();
    void copy(Myclass &my);
    void print();
    int getx();
    int gety();
    friend void copy(Myclass &a, Myclass &b);

private:
    int x, y;
};
void copy(Myclass &a, Myclass &b) {
    a.x = b.x;
    a.y = b.y;
}
Myclass::Myclass(int a, int b) { x = a, y = b; }
int Myclass::getx() { return x; }
int Myclass::gety() { return y; }
void Myclass::print() {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
void Myclass::copy(Myclass &my) {
    x = my.x;
    y = my.y;
}
int main() {
    Myclass a(1, 2), b(3, 4);
    cout << "Before:" << '\n';
    a.print();
    a.copy(b);
    cout << "After:" << '\n';
    a.print();
    Myclass c(5, 6), d(7, 8);
    cout << "Before:" << '\n';
    c.print();
    copy(c, d);
    cout << "After:" << '\n';
    c.print();
    return 0;
}
