#include "stdio.h"
#include "algorithm"

using namespace std;
int dic[100000], pre[100000];

int main()
{
    int ncup;
    
    scanf("%d", &ncup);
    for (int i = 0; i < ncup; i += 2)
    {
        scanf("%d%d", &dic[i], &dic[i + 1]);
    }
    sort(dic, dic + ncup*2);
    int n;
    scanf("%d", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    sort(pre, pre + n);
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        if(find)
    }

        return 0;
}

int find(int n, int x)
{
    for (int i = 0; i < n;i++)
    {
         if(dic[i])
    }
}