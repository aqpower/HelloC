#include <iostream>
#include <algorithm>
using namespace std;
class SET{
    public:
        SET(int *p, int n);
        bool operator==(int m);
        friend bool operator==(SET &s1, SET &s2);
        void print();
        ~SET();

    private:
        int *a;
        int len;
};
SET::SET(int *p, int n){
    memcpy(a, p, n * sizeof(int));
    len = n;
}
bool SET::operator==(int m){
    for (int i = 0; i < len;i++){
        if(*(a+i) == m){
            return true;
        }
    }
    return false;
}
bool operator==(SET &s1, SET &s2){
    sort(s1.a, s1.a + s1.len);
    sort(s2.a, s2.a + s2.len);
    if(s1.len != s2.len){
        return false;
    }
    for (int i = 0; i < s1.len;i++){
        if(*(s1.a+i) != *(s2.a+i)){
            return false;
        }
    }
    return true;
}
SET::~SET(){
    delete []a;
}
int main(){
    int a[105], b[105];
    int len1;
    cin >> len1;
    for (int i = 0; i < len1;i++){
        cin >> a[i];
    }
    SET a1(a, len1);
    int len2;
    cin >> len2;
    for (int i = 0; i < len2;i++){
        cin >> b[i];
    }
    SET a2(b, len2);
    int m;
    cin >> m;
    if(a1 == m){
        cout << 1;
    } else {
        cout << 0;
    }
    cout << '\n';
    if(a2 == m){
        cout << 1;
    } else {
        cout << 0;
    }
    cout << '\n';
    if(a1 == a2){
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}