#include <iostream>
#include <string>
using namespace std;

int main(){

    // string str = " 12.3 56.7";
    // string::size_type sz;  // ?unsighed int
    // double a = stod(str, &sz);
    // double b = stod(str, &sz);
    // double b = stod(str.substr(sz), &sz); // !gain the substr is the right way
    // cout << a << ' ' << b;

    // string str;
    // string::size_type sz;
    // getline(cin, str);
    // int a = stoi(str, NULL, 2); //todo nullptr

    // cout << a << '\n';

    int pi = 89;
    string str = to_string(pi);

    cout << str << '\n';

    return 0;
}

