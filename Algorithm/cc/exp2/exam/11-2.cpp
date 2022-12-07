#include <iostream>
#include <string>
using namespace std;

class Teacher{
    public:
        Teacher(int, int, int);
        virtual int getSumSal() = 0;
        virtual string getName() = 0;
        friend void print(Teacher*);

    protected:
        int worktime;
        int basesal;
        int unitPrice;
};
class lecturer: public Teacher{
    public:
        lecturer(int, int, int);
        int getSumSal();
        string getName();
};
class AssociateProfessor: public Teacher{
    public:
        AssociateProfessor(int, int, int, int);
        int getSumSal();
        string getName();

    private:
        int addtrans;
};
class Professor: public Teacher{
    public:
        Professor(int, int, int, int);
        int getSumSal();
        string getName();

    private:
        int addhouse;
};
Teacher::Teacher(int worktime, int base, int unit){
    this->worktime = worktime;
    this->basesal = base;
    this->unitPrice = unit;
}
lecturer::lecturer(int worktime, int base, int unit):Teacher(worktime,base,unit){}
int lecturer::getSumSal(){
    return basesal + worktime * unitPrice;
}
AssociateProfessor::AssociateProfessor(int worktime,int base, int unit, int add):Teacher(worktime, base, unit){
    addtrans = add;
}
Professor::Professor(int worktime,int base, int unit, int add):Teacher(worktime, base, unit){
    addhouse = add;
}
int AssociateProfessor::getSumSal(){
    return basesal + worktime * unitPrice + addtrans;
}
int Professor::getSumSal(){
    return basesal + worktime * unitPrice + addhouse;
}
string lecturer::getName(){
    return "Lecturer";
}
string AssociateProfessor::getName(){
    return "AssociateProfessor";
}
string Professor::getName(){
    return "Professor";
}
void print(Teacher* tquery){
    cout << tquery->getName() << " salary";
    if(!tquery->worktime){
        cout << " on vacation";
    }
    cout << ":" << tquery->getSumSal() << '\n';
}
int main(){
    int time, base, unit, add;
    cin >> time >> base >> unit;
    lecturer lec(time, base, unit);
    cin >> time >> base >> unit >> add;
    AssociateProfessor assprof(time, base, unit, add);
    cin >> time >> base >> unit >> add;
    Professor prof(time, base, unit, add);
    print(&lec);
    print(&assprof);
    print(&prof);
    return 0;
}