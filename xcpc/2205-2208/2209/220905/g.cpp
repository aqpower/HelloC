#include "iostream"
#include "algorithm"
#include "cmath"
#include "utility"
#include "string"
#include "cstring"
#include "map"
#include "vector"
#include "set"
#include "cstdio"
#include "list"

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int maxn = 100;

typedef struct
{
    int *data;
    int length;
    int max_size;
} sqList, *linkLinst;

// 1、建立顺序表
void initList(sqList &L)
{
    L.data = (int *)malloc(sizeof(int) * maxn);
    L.length = 0;
    L.max_size = maxn;
}
// 2、输出顺序表
void put(sqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
// 3.插入元素第i个位置
bool insetList(sqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= L.max_size)
    {
        int *newbase = (int *)realloc(L.data, (L.max_size + maxn) * sizeof(int));
        if (!newbase)
        {
            return false;
        }
        else
        {
            L.data = newbase;
            L.max_size += maxn;
        }
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
// 4.删除第i个元素
bool deleteList(sqList &L, int i)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    else
    {
        for (int j = i; j < L.length; j++)
        {
            L.data[j - 1] = L.data[j];
        }
        L.length--;
        return true;
    }
}
// 5.逆置顺序表
void reverse(sqList &L)
{
    int t, q = 0, p = L.length - 1;
    while (q < p)
    {
        t = L.data[q];
        L.data[q] = L.data[p];
        L.data[p] = t;
        q++;
        p--;
    }
}
// 6、删除其值相同元素
void delConEle(sqList &L)
{
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] == L.data[i - 1])
        {
            deleteList(L, i + 1);
            i--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    sqList L;
    int n, num;
    cout << "输入元素个数：" << endl;
    initList(L);

    cin >> n;
    cout << "输入数据：";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        insetList(L, L.length + 1, num);
    }

    cout << "输出线性表L:" << endl;
    int aa;
    cin >> aa;
    cout << aa;
    put(L);

    delConEle(L);
    cout << "输出删除值相同多余元素后的顺序表L:" << endl;
    put(L);

    reverse(L);
    cout << "输出逆置的顺序表L:" << endl;
    put(L);

    return 0;
}
