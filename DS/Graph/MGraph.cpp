// 图采用邻接矩阵表示，实现无向图的深度优先搜索与有向图的广度优先搜索
/*
8
A B C D E F G H
8
B A
A C
A D
B E
C F
C G
G H
F H
8
A B C D E F G H
8
B A
A C
A D
B E
C F
C G
G H
F H
*/

#include <iostream>
using namespace std;

#define MAX_VERTEX_NUM 20

#define VRType int
#define VertexType char
#define InfoType int

typedef enum { DG, DN, AG, AN } Graphkind;
//{有向图，有向网，无向图，无向网}

typedef struct ArcCell {
    VRType adj;
    InfoType* info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];  //顶点向量
    AdjMatrix arcs;
    int vexnum, arcnum;
    Graphkind kind;
} Mgraph;
// 邻接矩阵表示图

typedef int QElemType;
typedef struct QUEUE {
    QElemType data[MAX_VERTEX_NUM];
    int front;
    int rear;
} Queue;
void InitQueue(Queue& qu) { qu.front = qu.rear = 0; }
void EnQueue(Queue& qu, QElemType e) { qu.data[qu.rear++] = e; }
QElemType DeQueue(Queue& qu) { return qu.data[qu.front++]; }
QElemType QueueFront(Queue qu) { return qu.data[qu.front]; }
bool EmptyQueue(Queue& qu) { return qu.front == qu.rear; }

bool vis[MAX_VERTEX_NUM];

void InitMgraph(Mgraph& G) {
    G.vexnum = 0;
    G.arcnum = 0;
}

void Locate(Mgraph G, VertexType e, int& ind) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vexs[i] == e) {
            ind = i;
            return;
        }
    }
}

void CreateMgraph(Mgraph& G) {
    cin >> G.vexnum;
    getchar();
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.arcs[i][j].adj = 0;
        }
    }
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vexs[i];
    }
    cin >> G.arcnum;
    VertexType a, b;
    int cur1, cur2;
    for (int i = 0; i < G.arcnum; i++) {
        getchar();
        cin >> a >> b;
        Locate(G, a, cur1);
        Locate(G, b, cur2);
        G.arcs[cur1][cur2].adj = 1;
        if (G.kind == AG) {
            G.arcs[cur2][cur1].adj = 1;
        }
    }
}

void DeepFirstSearch(Mgraph& G, int now) {
    cout << G.vexs[now];
    vis[now] = true;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.arcs[now][i].adj == 1 && !vis[i]) {
            DeepFirstSearch(G, i);
        }
    }
}

void DeepFirstSearch(Mgraph G) {
    cout << "DFS: ";
    for (int i = 0; i < G.vexnum; i++) {
        vis[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!vis[i]) {
            DeepFirstSearch(G, i);
        }
    }
    cout << '\n';
}

void BorderFirstSearch(Mgraph& G, int now) {
    Queue q;
    InitQueue(q);
    EnQueue(q, now);
    vis[now] = true;
    while (!EmptyQueue(q)) {
        int top = DeQueue(q);
        cout << G.vexs[top];
        for (int i = 0; i < G.arcnum; i++) {
            if (G.arcs[top][i].adj == 1 && !vis[i]) {
                vis[i] = true;
                EnQueue(q, i);  // 入队时标记为true，否则可能重复进队
            }
        }
    }
}

void BorderFirstSearch(Mgraph& G) {
    cout << "BFS: ";
    for (int i = 0; i < G.vexnum; i++) {
        vis[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!vis[i]) {
            BorderFirstSearch(G, i);
        }
    }
    cout << '\n';
}

int main() {
    Mgraph Gag, Gdn;
    Gag.kind = AG;
    InitMgraph(Gag);
    CreateMgraph(Gag);
    cout << "无向图" << endl;
    DeepFirstSearch(Gag);
    BorderFirstSearch(Gag);

    Gdn.kind = DN;
    InitMgraph(Gdn);
    CreateMgraph(Gdn);
    cout << "有向图" << endl;
    DeepFirstSearch(Gdn);
    BorderFirstSearch(Gdn);

    return 0;
}