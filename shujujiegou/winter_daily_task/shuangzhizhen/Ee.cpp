#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
const int MAXN = 20005;
int i, m, n, yu[MAXN], lishan[MAXN], mycount[MAXN];

struct MOVIE
{
    int b_vid;
    int c_word;
} mov[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> yu[i];
    cin >> m;
    for (i = 0; i < m; i++)
        cin >> mov[i].b_vid;
    for (i = 0; i < m; i++)
        cin >> mov[i].c_word;
    sort(yu, yu + n);
    lishan[0] = 1;
    for (i = 1; i < n; i++)
    {
        if (yu[i] == yu[i - 1])
            lishan[i] = lishan[i - 1];
        else
            lishan[i] = i + 1;
    }
    memset(mycount, 0, sizeof(mycount));
    for (i = 0; i < n; i++)
    {
        mycount[lishan[i]]++;
    }
    int max = 0, num = 0, ho[100];
    for (i = 0; i < n; i++)
    {
        if (mycount[i] > max)
            max = mycount[i];
    }
    for (i = 0; i < n; i++)
    {
        if (mycount[i] == max)
        {
            ho[num++] = i;
        }
    }
    if (num == 1)
    {
        for (i = 0; i < m; i++)
        {
            if (mov[i].b_vid == yu[ho[0] - 1])
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
        for (i = 0; i < m; i++)
        {
            if (mov[i].c_word == yu[ho[0] - 1])
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    else
    {
        int j, jue[100], dj = 0;
        jue[0] = 1;
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (mov[j].b_vid == yu[ho[i] - 1])
                {
                    jue[num++] = j + 1;
                    break;
                }
            }
        }
        if (dj <= 1)
        {
            cout << jue[0] << endl;
        }
        else
        {
            
        }
    }

    return 0;
}
