#include <iostream>
using namespace std;

typedef struct LNode
{
	int data;
	LNode* next;
}*Linklist;

void print(Linklist& L)
{
	LNode* p = L->next;
	while (p)
	{
		cout << p->data << " ";
        p = p->next;
    }
	cout << endl;
}

void Init(Linklist& L,int n)
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* p,*q = NULL;
	while (n--)
	{
		p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data;
		L->next = p;
		L->next->next = q;
		q = L->next;
	}
}

int main()
{
	int n;
	cin >> n;
	Linklist L;
	Init(L, n);
	print(L);

	return 0;
}
