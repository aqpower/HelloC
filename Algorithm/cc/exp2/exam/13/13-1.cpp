#include <iostream>
using namespace std;
const double PI = 3.14;
class Cylinder {
public:
    Cylinder(double = 1, double = 1);
    Cylinder(Cylinder&);
    double getArea();
    double getVolume();

private:
    double *radius;
    double *high;
};
Cylinder::Cylinder(double r, double h){
    radius = new double(r);
    high = new double(h);
}
Cylinder::Cylinder(Cylinder& a){
    delete radius;
    delete high;
    radius = new double(*a.radius);
    high = new double(*a.high);
}
double Cylinder::getArea(){
    return 2 * PI * (*radius) * (*radius) + 2 * PI * (*radius) * (*high);
}
double Cylinder::getVolume(){
    return  PI * (*radius) * (*radius) * (*high);
}
int main(){
    double r, h;
    cin >> r >> h;
    Cylinder cy(r, h);
    cout << cy.getVolume() << '\n'
         << cy.getArea() << '\n';
    return 0;
}