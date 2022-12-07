#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct link_list
{
    int num;
    char sex[20];
    char name[30];
    struct link_list *next;
} STU;

void delRedundant(STU *head);
void insertNode(STU *h, STU data);
void reverseList(STU *head);
void Create(STU *head);
STU *combineList(STU *head1, STU *head2);
STU *findNode(STU *head1, char *x);
void print(STU *head1);
void ChaiFen(STU *head, STU *male, STU *female);
int len(STU *head);

int main()
{
    STU *head = (STU *)malloc(sizeof(STU));
    Create(head);
    


    return 0;
}

void Create(STU *head)
{
    STU *p, *q = head;
    int n;
    while (scanf("%d", &n), n > 0)
    {
        p = (STU *)malloc(sizeof(STU));
        p->num = n;
        scanf("%s%s", p->sex, p->name);
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

void print(STU *head1)
{
    while (head1 = head1->next, head1 != NULL)
    {
        printf("%d %s %s\n", head1->num, head1->sex, head1->name);
    }
}

void SortNode(STU *head)
{
    STU *t, *q = head, *p = q->next;
    int n = len(head) - 1;
    for (int i = 0; i < n - 1; i++)
    {
        q = head, p = q->next, t = p->next;
        while (1)
        {
            if (strcmp(p->name, t->name) > 0)
            {
                p->next = t->next;
                t->next = p;
                q->next = t;
            }
            if (!t->next)
                break;
            q = p, p = t, t = t->next;
        }
    }
}

int len(STU *head)
{
    int n = 0;
    while (head)
    {
        n++;
        head = head->next;
    }
    return n;
}

void delRedundant(STU *head, char *name)
{
    STU *p = head, *q = head->next;
    while (q)
    {
        if (!strcmp(q->name, name))
        {
            p->next = q->next;
            free(q);
            break;
        }
        p = q;
        q = q->next;
    }
}

STU *findNode(STU *head, char *x)
{
    STU *q = head;
    while (q = q->next, q != NULL)
    {
        if (!strcmp(q->name, x))
            return q;
    }
    return NULL;
}