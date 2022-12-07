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

void Create(STU *head);
void SortNode(STU *head);
void print(STU *head1);
int len(STU *head);

int main()
{
    STU *head = (STU *)malloc(sizeof(STU));
    Create(head);

    SortNode(head);

    print(head);

    return 0;
}

void Create(STU *head)
{
    int n;
    STU *p, *q = head;
    while (scanf("%d", &n), n > 0)
    {

        p = (STU *)malloc(sizeof(STU));
        scanf("%s%s", p->sex, p->name);
        p->num = n;
        q->next = p;
        q = p;
    }
    q->next = NULL;
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

void print(STU *head1)
{
    STU *q = head1->next;
    while (q)
    {
        printf("%d %s %s\n", q->num, q->sex, q->name);
        q = q->next;
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