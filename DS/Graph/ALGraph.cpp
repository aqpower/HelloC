/*
带权图采用邻接表表示，实现无向图的广度优先搜索与有向图的深度优先搜索
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
#define VertexType char
#define InfoType int

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
    InfoType* info;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode* first;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
    int kind; // 1表示无向
} ALGraph;

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

void Locate(ALGraph G, VertexType ver, int& cur)
{
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == ver) {
            cur = i;
            return;
        }
    }
}

void MyPush(VNode& v, int cur)
{
    ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = cur;
    p->nextarc = v.first;
    v.first = p;
}

void CreateALGraph(ALGraph& G)
{
    cin >> G.vexnum;
    getchar();
    for (int i = 0; i < G.vexnum; i++) {
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }
    cin >> G.arcnum;
    VertexType a, b;
    int cur1, cur2;
    for (int i = 0; i < G.arcnum; i++) {
        getchar();
        cin >> a >> b;
        Locate(G, a, cur1);
        Locate(G, b, cur2);
        MyPush(G.vertices[cur1], cur2);
        if (G.kind == 1) {
            MyPush(G.vertices[cur2], cur1);
        }
    }
}

bool vis[MAX_VERTEX_NUM];
void DeepFirstSearch(ALGraph G, int now)
{
    vis[now] = true;
    cout << G.vertices[now].data;
    ArcNode* p = G.vertices[now].first;
    while (p) {
        if (!vis[p->adjvex]) {
            DeepFirstSearch(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void DeepFirstSearch(ALGraph G)
{
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

void BorderFirstSearch(ALGraph G, int now)
{
    Queue q;
    EnQueue(q, now);
    vis[now] = true;
    while (!EmptyQueue(q)) {
        int top = DeQueue(q);
        cout << G.vertices[top].data;
        ArcNode* p = G.vertices[top].first;
        while (p) {
            if (!vis[p->adjvex]) {
                vis[p->adjvex] = true;
                EnQueue(q, p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

void BorderFirstSearch(ALGraph G)
{
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

int main()
{
    ALGraph G1;
    G1.kind = 1;
    CreateALGraph(G1);
    cout << "无向图遍历" << '\n';
    DeepFirstSearch(G1);
    BorderFirstSearch(G1);
    ALGraph G0;
    G1.kind = 0;
    CreateALGraph(G0);
    cout << "有向图遍历" << '\n';
    DeepFirstSearch(G0);
    BorderFirstSearch(G0);
    return 0;
}
