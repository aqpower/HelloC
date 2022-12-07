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
STU *findNode(STU *head, char *x);
void print(STU *h);

int main()
{
    STU *head = (STU *)malloc(sizeof(STU));
    Create(head);

    char tarname[20];
    scanf("%s", tarname);
    STU *tar = findNode(head, tarname);
    if (tar)
        print(tar);
    else
        printf("查无此人\n");

    return 0;
}

void Create(STU *head)
{
    STU *q = head, *p;
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

void print(STU *h)
{
    if (h)
        printf("%d %s %s\n", h->num, h->sex, h->name);
}