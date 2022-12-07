#include <iostream>
#include <math.h>
using namespace std;
class Point{
    public:
        Point(int, int);
        ~Point();
        int getx();
        int gety();

    private:
        int x;
        int y;
};
class Circle{
    public:
        Circle(int, int, int);
        ~Circle();
        friend int judge(Circle &a, Circle &b);

    private:
        int r;
        Point center;
};
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}
Circle::Circle(int x, int y, int r):center(x,y){
    this->r = r;
}
int Point::getx(){
    return x;
}
int Point::gety(){
    return y;
}
Circle::~Circle(){
    cout << "Circle destruct" << endl;
}
Point::~Point(){
    cout << "Point destruct" << endl;
}
int judge(Circle &a, Circle &b){
    int dis = abs(a.center.getx() - b.center.getx()) + abs(a.center.gety() - b.center.gety());
    int cmpr = abs(a.r - b.r);
    if(dis > a.r + b.r){
        return 1;
    } else if(dis == a.r + b.r){
        return 2;
    } else if(dis > cmpr){
        return 3;
    } else if(dis == cmpr){
        return 4;
    } else{
        return 5;
    }
}
int main(){
    int x, y, r;
    cin >> x >> y >> r;
    Circle a(x, y, r);
    cin >> x >> y >> r;
    Circle b(x, y, r);
    switch(judge(a, b)){
        case 1:
        cout << "liang yuan xiang li";
        break;
        case 2:
        cout << "liang yuan wai qie";
        break;
        case 3:
        cout << "liang yuan xiang jiao";
        break;
        case 4:
        cout << "liang yuan nei qie";
        break;
        case 5:
        cout << "liang yuan nei han";
    }
    cout << '\n';
    return 0;
}