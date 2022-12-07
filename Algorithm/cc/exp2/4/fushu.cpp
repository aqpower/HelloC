#include <iostream>
using namespace std;
class FS{
    public:
        FS(double, double);
        FS(){};
        void print();
        friend FS operator+(FS&, FS&);
        friend FS operator-(FS&, FS&);
        friend istream &operator>>(istream &, FS &);
        friend ostream &operator<<(ostream &, FS &);

    private:
        double sb;
        double xb;
};
FS::FS(double sb, double xb){
    this->sb = sb;
    this->xb = xb;
}
FS operator+(FS &a,FS & b){
    return FS(a.sb + b.sb, a.xb + b.xb);
}
FS operator-(FS &a, FS &b){
    return FS(a.sb - b.sb, a.xb - b.xb);
}
istream& operator >> (istream &is,FS &a){
    string s;
    getline(is, s);
    int ind = s.find(' ');
    a.sb = stoi(s.substr(0,ind));
    a.xb = stoi(s.substr(ind + 1, s.size() - ind - 1));
    return is;
}
ostream& operator << (ostream &os,FS &a){
    a.print();
    return os;
}
void FS::print(){
    if(sb && xb != 0){
        cout << sb;
    } else if(sb == 0 && xb == 0){
        cout << sb;
    } else if(sb && xb == 0){
        cout << sb;
    }
    if(xb > 0){
        if(sb){
            cout << '+';
        }
        if(xb == 1){
            cout << 'i';
        } else {
            cout << xb << 'i';
        }
    } else if(xb < 0){
        if(xb == -1){
            cout << "-i";
        } else {
            cout << xb << 'i';
        }
    }
    cout << '\n';
}
int main(){
    FS a, b, c, d;
    cout << "please enter the date:\n";
    cin >> a >> b;
    c = a + b;
    d = a - b;
    cout << c << d;
    cout << "please enter the date:\n";
    cin >> a >> b;
    c = a + b;
    d = a - b;
    cout << c << d;
    cout << "please enter the date:\n";
    cin >> a >> b;
    c = a + b;
    d = a - b;
    cout << c << d;
    cout << "please enter the date:\n";
    cin >> a >> b;
    c = a + b;
    d = a - b;
    cout << c << d;
    return 0;
}