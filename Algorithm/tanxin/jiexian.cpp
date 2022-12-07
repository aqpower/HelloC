#include <bits/stdc++.h>
using namespace std;

int n;           //物品数量
int limitWeight; //背包上限重量
const int maxn = 1010;
int bestValue = 0; //最优值 背包能装的最大价值

//物品node 两个属性 价值 和 重量
struct node
{
    int v;
    int w;
};

//定义排序规则
bool cmp(node a, node b)
{
    double flag1 = a.v * 1.0 / a.w;
    double flag2 = b.v * 1.0 / b.w;
    return flag1 > flag2; //按价值与重量比排序
}

struct node nod[maxn]; //存放物品的结构体数组
int takeNum[maxn];     //记录拿物品的数量
int bestTake[maxn];    //记录最优的 拿物品的数量

//第x个物品时 当前背包的重量 code by:fishers
void dfs(int x, int curWeight, int curValue)
{

    if (x == n + 1)
    { //递归出口 拿第x+1个物品了 就是到达了叶节点
        if (curValue > bestValue && curWeight <= limitWeight)
        {
            bestValue = curValue; //更新最优值
            for (int i = 1; i <= n; i++)
                bestTake[i] = takeNum[i];
        }
        return; //结束递归
    }

    int nextMaxValue = curValue + (limitWeight - curWeight) * (nod[x].v / nod[x].w); //分支界限: 以后最大也就是用背包剩下的重量全拿这个物品x(因为之前按重量价值比排序啦,小贪心)
    if (nextMaxValue < bestValue)
        return; //和最优值(已经搜索出的背包最大价值)比较(剪枝优化),小于最优值就直接返回了

    int curMaxNum = (limitWeight - curWeight) / nod[x].w; //当前一层最多拿物品x的个数 (以确保不超过最大背包重量上限limitWeight)
    for (int i = curMaxNum; i >= 0; i--)
    {                                              //枚举每一个分支 i表示拿这个物品的个数:拿i个
        int nextWeight = curWeight + i * nod[x].w; //如果这一次拿了i个物品 算出nextWeight重量 上一轮重量+这一轮i个物品x的重量
        if (nextWeight > limitWeight)
            continue;
        int nextActualValue = curValue + i * nod[x].v; //拿了i个物品后实际的价值
        takeNum[x] = i;                                //记录第x个物品 拿的个数i
        dfs(x + 1, nextWeight, nextActualValue);       //递归搜索下一个 物品的情况
        takeNum[x] = 0;
    }
}

void input()
{
    cin >> n >> limitWeight; //输入物品个数n,背包承受的重量上限
    for (int i = 1; i <= n; i++)
        cin >> nod[i].v; //输入每个物品的价值
    for (int i = 1; i <= n; i++)
        cin >> nod[i].w;             //输入每个物品的重量
    sort(nod + 1, nod + n + 1, cmp); //把物品按 价值重量比 排序 (贪心,也是后面分支界限来剪枝的前提)
}

int main()
{
    input();

    dfs(1, 0, 0);

    cout << "背包最多装的价值是" << bestValue << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "拿了" << bestTake[i] << "个"
             << "重量为" << nod[i].w << ",价值为" << nod[i].v << "的物品." << endl;
    }
    return 0;
}

/*
4 10
1 3 5 9
2 3 4 7
*/