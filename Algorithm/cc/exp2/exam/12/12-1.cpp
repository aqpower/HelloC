#include <iostream>
#include <string>
using namespace std;
class score{
    public:
        score(double, double, double);
        double get1();
        double get2();
        double get3();

    private:
        double sub1;
        double sub2;
        double sub3;
        double ave;
};
class stu{
    public:
        static double totalstudent;
        static double totalscore;
        stu(string, string, double, double, double);
        string getName();
        string getId();
        score getSco();

    private:
        string name;
        string id;
        score sco;
};
double stu::totalstudent = 0;
double stu::totalscore = 0;
score::score(double a,double b,double c):sub1(a),sub2(b),sub3(c){}
stu::stu(string name, string id, double a, double b, double c) :sco(a,b,c){
    this->name = name;
    this->id = id;
    totalscore += a + b + c;
    totalstudent++;
}
string stu::getName(){
    return name;
}
string stu::getId(){
    return id;
}
score stu::getSco(){
    return sco;
}
double score::get1(){
    return sub1;
}
double score::get2(){
    return sub2;
}
double score::get3(){
    return sub3;
}
int main(){
    double n;
    cin >> n;
    while(n--){
        string name, id;
        double a, b, c;
        cin >> name >> id >> a >> b >> c;
        stu stua(name, id, a, b, c);
        cout << stua.getName() << '\n';
        score tsco = stua.getSco();
        cout << stua.getId() << ' ' << tsco.get1() << ' ' << tsco.get2() << ' ' << tsco.get3() << '\n';
    }
    cout << "Totalnumber:" << stu::totalstudent << '\n';
    if(stu::totalscore){
        cout << "avescore:" << stu::totalscore / 3 / stu::totalstudent;
    } else {
        cout << "avescore:" << 0;
    }
    return 0;
}