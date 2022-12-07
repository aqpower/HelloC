#include <iostream>
#include <string>
using namespace std;

class XS{
    public:
        virtual void dispXM() = 0;
        virtual void dispXB() = 0;
        virtual void dispNL() = 0;
};

class CZS :public XS{
    public:
        CZS(string, string, int);
        void dispXM();
        void dispXB();
        void dispNL();

    private:
        string xm;
        string xb;
        int age;
};
class GZS :public XS{
    public:
        GZS(string, string, int);
        void dispXM();
        void dispXB();
        void dispNL();

    private:
        string xm;
        string xb;
        int age;
};
class DXS :public XS{
    public:
        DXS(string, string, int);
        void dispXM();
        void dispXB();
        void dispNL();

    private:
        string xm;
        string xb;
        int age;
};

void CZS::dispNL(){
    cout << age;
}
void CZS::dispXB(){
    cout << xb;
}
void CZS::dispXM(){
    cout << xm;
}
void GZS::dispNL(){
    cout << age;
}
void GZS::dispXB(){
    cout << xb;
}
void GZS::dispXM(){
    cout << xm;
}
void DXS::dispNL(){
    cout << age;
}
void DXS::dispXB(){
    cout << xb;
}
void DXS::dispXM(){
    cout << xm;
}

CZS::CZS(string xm, string xb, int age){
    this->xm = xm;
    this->xb = xb;
    this->age = age;
}
GZS::GZS(string xm, string xb, int age){
    this->xm = xm;
    this->xb = xb;
    this->age = age;
}
DXS::DXS(string xm, string xb, int age){
    this->xm = xm;
    this->xb = xb;
    this->age = age;
}
void disp(XS *p){
    p->dispXM();
    cout << ' ';
    p->dispXB();
    cout << ' ';
    p->dispNL();
    cout << '\n';
}

void disp2(XS *p){
    p->dispXM();
    cout << ' ';
    p->dispNL();
    cout << ' ';
    p->dispXB();
    cout << '\n';
}

int main(){
    string xm, xb;
    int age;
    cin >> xm >> xb >> age;
    CZS c(xm, xb, age);
    cin >> xm >> xb >> age;
    GZS g(xm, xb, age);
    cin >> xm >> xb >> age;
    DXS d(xm, xb, age);
    XS *pc = &c, *pg = &g, *pd = &d;
    disp(pc);
    disp(pg);
    disp(pd);

    XS &rc = c, &rg = g, &rd = d;
    disp2(&rc);
    disp2(&rg);
    disp2(&rd);

    return 0;
}