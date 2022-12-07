#include <iostream>
using namespace std;
class car{
    public:
        car(int, double, int);
        int getCost(int); 
        int getTotalPassengers(int);
        double getTotalWeight(int);

    protected:
        int nman;
        double ngoods;
        int cost;
};
car *dat[15];
class bus : public car{
    public:
        bus(int, double, int);
};
class pickup : public car{
    public:
        pickup(int, double, int);
};
class truck :public car{
    public:
        truck(int, double, int);
};
car::car(int nman, double ngoods, int cost){
    this->nman = nman;
    this->ngoods = ngoods;
    this->cost = cost;
}
bus::bus(int nman,double ngoods, int cost):car(nman, ngoods, cost){
}
int car::getCost(int day){
    return day * cost;
}
pickup::pickup(int nman, double ngoods, int cost):car(nman, ngoods, cost){
}
truck::truck(int nman, double ngoods, int cost):car(nman, ngoods, cost){
}
int car::getTotalPassengers(int day){
    return day * nman;
}
double car::getTotalWeight(int day){
    return day * ngoods;
}

void init(){
    dat[1] = new bus(5, 0, 800);
    dat[2] = new bus(5, 0, 400);
    dat[3] = new bus(5, 0, 800);
    dat[4] = new bus(51, 0, 1300);
    dat[5] = new bus(55, 0, 1500);
    dat[6] = new pickup(5, 0.45, 500);
    dat[7] = new pickup(5, 2.0, 450);
    dat[8] = new truck(0, 3, 200);
    dat[9] = new truck(0, 25, 1500);
    dat[10] = new truck(0, 35, 2000);
}
int main(){
    init();
    int todo;
    cin >> todo;
    if(todo){
        int ncar, totalPassengers = 0, totalCost = 0;
        double totalWeight = 0;
        cin >> ncar;
        for(int i = 0;i < ncar;i++){
            int m, n;
            cin >> m >> n;
            totalPassengers += dat[m]->getTotalPassengers(n);
            totalWeight += dat[m]->getTotalWeight(n);
            totalCost += dat[m]->getCost(n);
        }
        printf("%d %.2lf %d\n", totalPassengers, totalWeight, totalCost);
    } else {
        cout << "0 0.00 0" << '\n';
    }
    return 0;
}