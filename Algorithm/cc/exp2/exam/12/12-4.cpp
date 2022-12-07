#include <iostream>
#include <cmath>
using namespace std;
class CRational{
    public:
        CRational(int, int);
        CRational(){}
        void mostSimplified();
        void print();
        friend CRational operator+(const CRational&, const CRational&);
        friend CRational operator*(const CRational&, const CRational&);

    private:
        int molucule;
        int maternal;
};
int mygcd(int a, int b){
    if(b == 0){
        return 1;
    }
    if(a % b == 0){
        return b;
    }
    return mygcd(b, a % b);
}
CRational::CRational(int mo, int ma) : molucule(mo), maternal(ma) { mostSimplified(); }
void CRational::mostSimplified(){
    int maxgcd = mygcd(maternal, molucule);
    molucule /= maxgcd;
    maternal /= maxgcd;
}
void CRational::print(){
    if(abs(maternal) == 1){
        cout << molucule * maternal << '\n';
    } else {
        if(maternal * molucule < 0){
            cout << "-";
        }
        cout << abs(molucule) << "/" << abs(maternal) << '\n';
    } 
}
CRational operator+(const CRational &a,const CRational &b){
    CRational t;
    t.maternal = a.maternal * b.maternal;
    t.molucule = a.molucule * b.maternal + b.molucule * a.maternal;
    t.mostSimplified();
    return t;
}
CRational operator*(const CRational &a,const CRational &b){
    CRational t;
    t.maternal = a.maternal * b.maternal;
    t.molucule = a.molucule * b.molucule;
    t.mostSimplified();
    return t;
}
int main(){
    int mo, ma, mo1, ma1;
    cin >> mo >> ma;
    CRational a(mo, ma);
    cin >> mo1 >> ma1;
    CRational b(mo1, ma1);
    if(ma1 == 0 || ma == 0){
        cout << "Error!" << '\n';
    } else {
        (a + b).print();
        (a * b).print();
    }
    return 0;
}