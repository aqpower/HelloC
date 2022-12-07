#include "stdio.h"
#include "stdlib.h"

typedef struct link_list
{
    int num;
    char sex[20];
    char name[30];
    struct link_list *next;
} STU;

void Create(STU *head);
void print(STU *head1);

int main()
{
    STU *head = (STU *)malloc(sizeof(STU));
    Create(head);

    print(head);

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