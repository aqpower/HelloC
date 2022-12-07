#include <bits/stdc++.h>
using namespace std;
class Student

{public:

    Student(int=0);    Student(Student &);   ~Student();  

private:

        int age;

};

Student::Student(int age){this->age=age;cout<<"Constructor  "<<this->age<<endl;}

Student::Student(Student &s){age=s.age+30;cout<<"Copy Constructor  "<<this->age<<endl;}

Student::~Student(){cout<<"Destructor  "<<age<<endl;}

void test()

{Student s4(4); static Student s5(5); Student s6(6); Student s7(s4);

 cout<<"test  is called"<<endl;

}

Student s1(1);

int main()

{Student s2(2);

 static Student s3(3);

 Student s8(8);

 Student s9(s2);

  test(); 

  cout<<"main end"<<endl;

}