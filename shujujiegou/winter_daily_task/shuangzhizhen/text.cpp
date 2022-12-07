#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct ins
{
    int start;
    int end;
} ins;

int ComPare(ins A, ins B)
{
    return A.start < B.start;
}
int max(int a, int b);

int main()
{
    int n;
    ins dic[50005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &dic[i].start, &dic[i].end);
    }
    sort(dic, dic + n, ComPare);
    int start = dic[0].start, end = dic[0].end;

    for (int i = 1; i < n;i++)
    {
        if(dic[i].start<=end)
        {
            end = max(dic[i].end, end);

        }
        else
        {
            printf("no\n");
            return 0;
        }
    }

    printf("%d %d\n", start, end);
    
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}