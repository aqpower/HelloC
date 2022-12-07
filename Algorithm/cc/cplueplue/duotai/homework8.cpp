#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class Cshape{
    public:
        virtual double getarea() = 0;
        virtual void PrintInfo() = 0;
};
class CRectangle: public Cshape{
    public:
        CRectangle(int, int);
        double getarea();
        void PrintInfo();
    private:
        int a, b;
};
class CCircle: public Cshape{
    public:
        CCircle(int);
        double getarea();
        void PrintInfo();
    private:
        int r;
};
class CTriangle:public Cshape{
    public:
        CTriangle(int a, int b, int c);
        double getarea();
        void PrintInfo();
    private:
        int a, b, c;
        int sumEdge;
};
CRectangle::CRectangle(int a, int b){
    this->a = a, this->b = b;
}
void CRectangle::PrintInfo(){
    printf("Rectangle:%.0lf\n", getarea());
}
double CRectangle::getarea(){
    return a * b;
} 
CCircle::CCircle(int r){
    this->r = r;
}
void CCircle::PrintInfo(){
    printf("Circle:%.2lf\n", getarea());
}
double CCircle::getarea(){
    return 3.14 * r * r;
}
CTriangle::CTriangle(int a, int b, int c){
    sumEdge = a + b + c;
    this->a = a, this->b = b, this->c = c;
}
double CTriangle::getarea(){
    double p = sumEdge / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
void CTriangle::PrintInfo(){
    double s = getarea();
    if(s - (int)s == 0){
        printf("Triangle:%.0lf\n", getarea());
    } else {
        printf("Triangle:%.2lf\n", getarea());
    }
}
int cmp(const void* a,const void *b){
    Cshape** pa = (Cshape**)a;
    Cshape** pb = (Cshape**)b;
    return ((*pa)->getarea() > (*pb)->getarea());
}

int main(){
    int n;
    int c1, c2, c3;
    cin >> n;
    Cshape* dat[100];
    string s;
    for (int i = 0; i < n;i++){
        cin >> s;
        if(s == "Rectangle"){
            cin >> c1 >> c2;
            CRectangle *pr = new CRectangle(c1, c2);
            dat[i] = pr;
        } else if(s == "Circle"){
            cin >> c1;
            CCircle *pc = new CCircle(c1);
            dat[i] = pc;
        } else {
            cin >> c1 >> c2 >> c3;
            CTriangle *pt = new CTriangle(c1, c2, c3);
            dat[i] = pt;
        }
    }
    qsort(dat, n, sizeof(Cshape *), cmp);
    for (int i = 0; i < n;i++){
        dat[i]->PrintInfo();
    }
    return 0;
}