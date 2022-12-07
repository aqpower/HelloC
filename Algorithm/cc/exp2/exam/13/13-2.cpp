#include <iostream>
using namespace std;
class goods{
    public:
        goods(int, double);
        static double discount;
        static double sumSales;
        static int nSold;
        static double average();
        static void display();

    private:
        double numSold;
        double unitPrice;
};
double goods::discount = 0.9;
double goods::sumSales = 0;
int goods::nSold = 0;
goods::goods(int numSold, double unitPrice){
    nSold += numSold;
    double nowsales = numSold * unitPrice * discount;
    if(numSold > 10){
        nowsales *= 0.98;
    }
    sumSales += nowsales;
    this->numSold = numSold;
    this->unitPrice = unitPrice;
}
double goods::average(){
    return sumSales / nSold;
}
void goods::display(){
    cout << sumSales << '\n'
         << average() << '\n';
}

int main(){
    int n;
    cin >> n;
    if(n){
        while(n--){
            double numtoBuy, unitPrice;
            cin >> numtoBuy >> unitPrice;
            goods a(numtoBuy, unitPrice);
        }
        goods::display();
    } else {
        cout << "you can go home" << '\n';
    }
    return 0;
}