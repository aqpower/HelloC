#include <iostream>
using namespace std;
class Date{
    public:
        void showDate();
        void addDate();
        bool setDate(int = 2000,int = 1,int = 1);
    private:
        int year;
        int month;
        int day;
        bool isVaild(int, int, int);
        bool isLeap(int);
};

bool Date::isLeap(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
bool Date::isVaild(int y, int m, int d){
    if(y <= 0 || m <= 0 || d <= 0 || d > 31 || m > 12 || y > 9999){
        return false;
    }
    int daylimit = 31;
    switch(m){
        case 4 :
        case 6 :
        case 9 :
        case 11 :
            daylimit = 30;
            break;
        case 2:
            daylimit = isLeap(y) ? 29 : 28;
    }
    if(d > daylimit){
        return false;
    }
    return true;
}
void Date::showDate(){
    printf("%02d/%02d/%d\n", day, month, year);
}
void Date::addDate(){
    if(isVaild(year, month, day + 1)){
        day += 1;
    } else if(isVaild(year, month + 1, 1)){
        day = 1;
        month += 1;
    } else if(isVaild(year + 1, 1, 1)){
        year += 1;
        month = 1;
        day = 1;
    } else {
        year = 2000, month = 1, day = 1;
    }
}
bool Date::setDate(int y, int m, int d){
    if(isVaild(y, m, d)){
        year = y, month = m, day = d;
        return true;
    } else {
        year = 2000, month = 1, day = 1;
        return false;
    }
}

int main(){
    Date a;
    int y, m, d;
    while(1){
        cout << "Please enter the data: ";
        cin >> y >> m >> d;
        a.setDate(y, m, d);
        while(!a.setDate(y, m, d)){
            cout << "WRONG DATE!" << '\n';
            cout << "Please reenter the data: ";
            cin >> y >> m >> d;
        }
        cout << "Today: ";
        a.showDate();
        a.addDate();
        cout << "One day pass: ";
        a.showDate();
    }
    return 0;
}