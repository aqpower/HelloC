#include <iostream>
#include <string>
using namespace std;
class Money{
    public:
        Money(int, int, int);
        Money(){}
        friend Money operator+(Money, Money);
        friend Money operator-(Money, Money);
        friend istream& operator>>(istream&, Money&);
        friend ostream& operator<<(ostream&, Money);

    private:
        int fen;
        int jiao;
        int yuan;
};
Money::Money(int yuan, int jiao, int fen){
    this->yuan = yuan;
    this->jiao = jiao;
    this->fen = fen;
}
Money operator+(Money a, Money b){
    Money t;
    t.fen = (a.yuan + b.yuan) * 100 + (a.jiao + b.jiao) * 10 + a.fen + b.fen;
    t.yuan = t.fen / 100;
    t.fen %= 100;
    t.jiao = t.fen / 10;
    t.fen %= 10;
    return t;
}
Money operator-(Money a, Money b){
    Money t;
    t.fen = (a.yuan - b.yuan) * 100 + (a.jiao - b.jiao) * 10 + a.fen - b.fen;
    t.yuan = t.fen / 100;
    t.fen %= 100;
    t.jiao = t.fen / 10;
    t.fen %= 10;
    return t;
}
istream& operator>>(istream& is,Money &a){
    string s;
    string y, j, f;
    getline(is, s);
    int ge = 1;
    for (int i = 0; i < s.size();i++){
        if(s[i] == ' '){
            ge++;
        } else {
            if(ge == 1){
                y += s[i];
            } else if(ge == 2){
                j += s[i];
            } else {
                f += s[i];
            }
        }
    }
    a.yuan = stoi(y);
    a.jiao = stoi(j);
    a.fen = stoi(f);
    return is;
}
ostream& operator<<(ostream &os, Money a){
    if(a.fen < 0 ){
        cout << "-" << -a.yuan << "yuan" << -a.jiao << "jiao" << -a.fen << "fen";
    } else {
        cout << a.yuan << "yuan" << a.jiao << "jiao" << a.fen << "fen";
    }
    cout << '\n';
    return os;
}
int main(){
    Money a, b;
    cin >> a >> b;
    cout << a + b;
    cout << a - b;
    return 0;
}