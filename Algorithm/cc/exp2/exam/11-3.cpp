#include <iostream>
using namespace std;
class Matrix{
    public:
        void init();
        void show();
        bool judgeplus(Matrix a);
        bool judgemult(Matrix a);
        friend Matrix operator+(Matrix, Matrix);
        friend Matrix operator*(Matrix, Matrix);

    private:
        int r, c;
        int a[25][25];
};
void Matrix::init(){
    cin >> r >> c;
    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            cin >> a[i][j];
        }
    }
}
void Matrix::show(){
    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            printf("%4d", a[i][j]);
        }
        cout << '\n';
    }
}
bool Matrix::judgeplus(Matrix a){
    if(r != a.r || c != a.c){
        return false;
    }
    return true;
}
bool Matrix::judgemult(Matrix a){
    if(c != a.r){
        return false;
    }
    return true;
}
Matrix operator+(Matrix a, Matrix b){
    Matrix t;
    t.r = a.r;
    t.c = a.c;
    for (int i = 0; i < t.r;i++){
        for (int j = 0; j < t.c;j++){
            t.a[i][j] = a.a[i][j] + b.a[i][j];
        }
    }
    return t;
}
Matrix operator*(Matrix a, Matrix b){
    Matrix t;
    t.r = a.r;
    t.c = b.c;
    for (int i = 0; i < t.r;i++){
        for (int j = 0; j < t.c;j++){
            t.a[i][j] = 0;
            for (int k = 0; k < a.c;k++){
                t.a[i][j] += a.a[i][k] * b.a[k][j];
            }
        }
    }
    return t;
}
int main(){
    Matrix a, b;
    a.init();
    b.init();
    cout << "A+B" << '\n';
    if(a.judgeplus(b)){
        Matrix m = a + b;
        m.show();
    } else {
        cout << "Error" << '\n';
    }
    cout << "A*B" << '\n';
    if(a.judgemult(b)){
        Matrix m = a * b;
        m.show();
    } else {
        cout << "Error" << '\n';
    }
    return 0;
}