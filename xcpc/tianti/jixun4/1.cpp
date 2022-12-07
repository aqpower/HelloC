#include <iostream>
using namespace std;

int main()
{
    int pa, pb, da = 0, db = 0;
    cin >> pa >> pb;
    int t = 3, dt;
    while (t--)
    {
        cin >> dt;
        if (dt)
            db++;
        else
            da++;
    }
    if (da)
    {
        if (pa > pb)
        {
            printf("The winner is a: %d + %d\n", pa, da);
            return 0;
        }
    }
    printf("The winner is b: %d + %d\n", pb, db);
    return 0;
}