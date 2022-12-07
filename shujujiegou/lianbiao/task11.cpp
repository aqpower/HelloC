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
void delRedundant(STU *head, char *name);
void print(STU *head1);


int main()
{
    STU *head = (STU *)malloc(sizeof(STU));
    Create(head);

    char name[20];
    scanf("%s", name);
    delRedundant(head, name);

    print(head);

    return 0;
}

void Create(STU *head)
{
    STU *p, *q = head;
    int n;
    while (scanf("%d", &n), n > 0)
    {
        STU *p = (STU *)malloc(sizeof(STU));
        scanf("%s%s", p->sex, p->name);
        p->num = n;
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