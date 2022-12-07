#include <iostream>
using namespace std;
class Time{
    public:
        bool setTime(int = 0, int = 0, int = 0);
        void showTime();
    private:
        bool isValid(int, int, int);
        int hour;
        int min;
        int sec;
};
bool Time::isValid(int h, int m, int s){
    return (h < 24 && h >= 0) && (m < 60 && m >= 0) && (s < 60 && s >= 0);
}
bool Time::setTime(int h, int m, int s){
    if(isValid(h, m, s)){
        hour = h, min = m, sec = s;
        return true;
    } else {
        hour = 0, min = 0, sec = 0;
        return false;
    }
}
void Time::showTime(){
    printf("%02d:%02d:%02d\n", hour, min, sec);
}
int main(){
    int h, m, s;
    Time a;
    cout << "Please enter the time: ";
    cin >> h >> m >> s;
    while(!a.setTime(h, m, s)){
        cout << "WRONG DATE!" << '\n'
             << "Please enter the time again: ";
        cin >> h >> m >> s;
    }
    cout << "Now: ";
    a.showTime();

    return 0;
}