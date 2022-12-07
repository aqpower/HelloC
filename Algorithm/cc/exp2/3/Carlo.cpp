#include "iostream"
#include "Carlo.h"
using namespace std;
double Carlo::TotalPrice=0.0;
double Carlo::TotalWeight=0.0;
Carlo::Carlo(double Weight, double Price){
    BoxWeight = Weight;
    BoxPrice = Price;
    BuyBox();
}
void Carlo::BuyBox(){
    TotalWeight += BoxWeight;
    TotalPrice += BoxPrice;
}
const double &Carlo::GetCurrentTotalPrice() const{
    return TotalPrice;          
}
const double &Carlo::GetCurrentTotalWeight() const{
    return TotalWeight;
}
void Carlo::SetCarlo(double Weight, double Price){
    BoxWeight = Weight;
    BoxPrice = Price;
}
void Carlo::SellBox(){
    delete this;
}
void Carlo::ShowBoxInfor() const{
    cout << "Current total price: " << GetCurrentTotalPrice() << '\n';
    cout << "Current total weight: " << GetCurrentTotalWeight() << '\n';
}
Carlo::~Carlo(){
    TotalPrice -= BoxPrice;
    TotalWeight -= BoxWeight;
}
