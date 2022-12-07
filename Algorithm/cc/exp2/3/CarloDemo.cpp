#include "iostream"
using namespace std;

class Carlo{
    public:
        Carlo(double Weight = 0, double Price = 0);
        virtual ~Carlo();
        void SetCarlo(double = 0, double = 0);
        const double &GetCurrentTotalWeight() const;
        const double &GetCurrentTotalPrice() const;
        void BuyBox(double, double);
        void SellBox(double, double);
        void ShowBoxInfor() const;

    protected:
        static double TotalWeight;
        static double TotalPrice;

    private:
        double BoxWeight;
        double BoxPrice;
};

double Carlo::TotalPrice = 0.0;
double Carlo::TotalWeight = 0.0;
Carlo::Carlo(double Weight, double Price) {
    BoxWeight = Weight;
    BoxPrice = Price;
}
void Carlo::BuyBox(double w, double v) {
        BoxWeight += w;
        BoxPrice += v;
        TotalWeight += w;
        TotalPrice += v;
}
const double& Carlo::GetCurrentTotalPrice() const {
    return TotalPrice;
}
const double& Carlo::GetCurrentTotalWeight() const {
    return TotalWeight;
}
void Carlo::SetCarlo(double Weight, double Price) {
    TotalPrice -= BoxPrice;
    TotalWeight -= BoxWeight;
    BoxWeight = Weight;
    BoxPrice = Price;
    TotalPrice += BoxPrice;
    TotalWeight += BoxWeight;
}
void Carlo::SellBox(double w, double v) {
        BoxWeight -= w;
        BoxPrice -= v;
        TotalWeight -= w;
        TotalPrice -= v;
}
void Carlo::ShowBoxInfor() const {
    cout << "TotalWeight:" << TotalWeight << '\n';
    cout << "TotalPrice:" << TotalPrice << '\n';
}
Carlo::~Carlo() {
}

int main()
{
    double w, v;
    char c;
    int cnt = 0;
    while(cin >> w >> v >> c){
        Carlo a(w,v);
        if(c == 'b'){
            a.BuyBox(w,v);
        } else {
            a.SellBox(w, v);
        }
        a.ShowBoxInfor();
    }

    return 0;
}
