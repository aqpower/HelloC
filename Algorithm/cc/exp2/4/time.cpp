#include <iostream>
using namespace std;
class Time{
    public:
        Time(){}
        Time(int, int, int);
        void SetTime(int,int,int);
        void Display();
        Time operator + (Time &a);
        Time operator - (Time &a);
        friend istream& operator>>(istream &, Time &);
        friend istream &operator<<(istream &, Time &);

    private:
        int hour,minute,second;
};
istream& operator >> (istream &is, Time &a){
    string s,sub;
    int cnt = 1;
    getline(is, s);
    for (int i = 0; i < s.size();i++){
        if(s[i] != ' '){
            sub += s[i];
        } else {
            if(cnt == 1){
                a.hour = stoi(sub);
                cnt++;
            } else if(cnt == 2){
                a.minute = stoi(sub);
                cnt++;
            }
            sub.clear();
        }
    }
    a.second = stoi(sub);
    return is;
}
ostream& operator << (ostream &os, Time &a){
    a.Display();
    return os;
}
Time::Time(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}
void Time::SetTime(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}
void Time::Display(){
    printf("%02d:%02d:%02d\n", hour, minute, second);
}
Time Time::operator+(Time &a){
    double h = hour + a.hour;
    double m = minute + a.minute;
    double s = second + a.second;
    if(s >= 60){
        s -= 60;
        m++;
    }
    if(m >= 60){
        m -= 60;
        h++;
    }
    if(h >= 24){
        h -= 24;
    }
    return Time(h, m, s);
}
Time Time::operator-(Time &a){
    double h = hour - a.hour;
    double m = minute - a.minute;
    double s = second - a.second;
    if(s < 0){
        s += 60;
        m--;
    }
    if(m < 0){
        m += 60;
        h--;
    }
    if(h < 0){
        h += 24;
    }
    return Time(h, m, s);
}
int main(){
    Time a, b;
    cin >> a >> b;
    Time c = a + b, d = a - b;
    cout << c << d;
    return 0;
}
