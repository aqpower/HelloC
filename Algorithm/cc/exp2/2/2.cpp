#include <iostream>
using namespace std;

class Rect{
    public:
        Rect(float, float);
        Rect(Rect &);
        ~Rect();
        void set(float, float);
        float GetPerimeter();
        float GetArea();

    private:
        float *Length;
        float *Width;
};
Rect::Rect(float l = 1, float w = 1){
    Length = new float(l);
    Width = new float(w);
}
Rect::Rect(Rect &r){
    Length = new float(*r.Length);
    Width = new float(*r.Width);
}
Rect::~Rect(){
    delete Length, Width;
}
void Rect::set(float l = 0, float w = 0){
    *Length = l;
    *Width = w;
}
float Rect::GetPerimeter(){
    return 2 * (*Length + *Width);
}
float Rect::GetArea(){
    return (*Length) * (*Width);
}
int main(){
    float l, w;
    cin >> l >> w;
    Rect t(l,w);
    Rect b = t;
    cout << b.GetPerimeter() << ' ' << b.GetArea() << '\n';
    return 0;
}
