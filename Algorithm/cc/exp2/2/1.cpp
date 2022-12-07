#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    public:
        Employee(char *, char*, char*, char*, char*);
        void ChangeName(char *);
        void ChangeAddress(char *);
        void ChangeCity(char *);
        void ChangeProvince(char *);
        void ChangePostalCode(char *);
        void Display();

    protected:
        char name[20];
        char address[20];
        char city[20];
        char province[20];
        char postalCode[20];
};
Employee::Employee(char *name_, char *address_, char *city_, char *province_, char *postalCode_){
    strcpy(name, name_);
    strcpy(city, city_);
    strcpy(province, province_);
    strcpy(address, address_);
    strcpy(postalCode, postalCode_);
}
void Employee::ChangeName(char *name_){
    strcpy(name, name_);
}
void Employee::ChangeAddress(char *address_){
    strcpy(address, address_);
}
void Employee::ChangeCity(char *city_){
    strcpy(city, city_);
}
void Employee::ChangeProvince(char *province_){
    strcpy(province, province_);
}
void Employee::ChangePostalCode(char *postalCode_){
    strcpy(postalCode, postalCode_);
}
void Employee::Display(){
    cout << name << '\n'
         << address << '\n'
         << city << '\n'
         << province << '\n' 
         << postalCode << '\n';
}

int main(){
    char na[20], ad[20], ci[20], pro[20], post[20];
    cin >> na >> ad >> ci >> pro >> post;
    Employee t(na,ad,ci,pro,post);
    cin >> na >> ad >> ci >> pro >> post;
    t.ChangeName(na);
    t.ChangeAddress(ad);
    t.ChangeCity(ci);
    t.ChangeProvince(pro);
    t.ChangePostalCode(post);
    t.Display();

    return 0;
}