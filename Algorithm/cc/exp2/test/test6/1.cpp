#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//带头节点 尾插法的链表！

typedef struct link_list
{
    int num;
    char sex[20];
    char name[30];
    struct link_list *next;
} STU;

void scan(STU *h)
{
    scanf("%d%s%s", &h->num, h->sex, h->name);
}

void print(STU *h)
{
    printf("%d\t%s\t%s\n", h->num, h->sex, h->name);
}

void output(STU *h)
{
    while (h = h->next, h != NULL)
        print(h);
}

void create(STU *h)
{
    int num;
    STU *p, *q = h;
    printf("Please enter the date of num,sex,name:\n");
    while (scanf("%d", &num), num > 0)
    {
        p = (STU *)malloc(sizeof(STU));
        p->num = num;
        scanf("%s", p->sex);
        scanf("%s", p->name);
        q->next = p;
        q = p;
    }
    q->next = NULL;
    output(h);
}

STU *findnum(STU *h, int num)
{
    while (h = h->next, h)
    {
        if (h->num == num)
            return h;
    }
    return NULL;
}

STU *findname(STU *h, char *name)
{
    while (h = h->next, h)
    {
        if (strcmp(name, h->name) == 0)
            return h;
    }
    return NULL;
}

void delectnum(STU *h, int n)
{
    STU *p = h, *q;
    while (q = p->next, q)
    {
        if (q->num == n)
        {
            p->next = q->next;
            free(q);
            return;
        }
        p = p->next;
    }
    printf("no same date;\n");
}

STU *insert(STU *h, int n)
{
    if (n < 1)
    {
        printf("value of i error.");
        return h;
    }
    else
    {
        STU *node = (STU *)malloc(sizeof(STU));
        printf("Please enter the date of num,sex,name:");
        scan(node);
        n--;
        while (n-- && h->next != NULL)
            h = h->next;
        node->next = h->next;
        h->next = node;
    }
}

int main()
{
    STU *head = (STU *)malloc(sizeof(STU));

    create(head);

    int n;
    printf("Please enter the num you want you find:");
    scanf("%d", &n);
    STU *temp = findnum(head, n);
    if (temp)
        print(temp);
    else
        printf("unable to find data\n");

    char name[9];
    getchar();
    printf("Please enter the name you want you find:");
    gets(name);
    STU *loname = findname(head, name);
    if (loname)
        print(loname);
    else
        printf("unable to find the name.\n");

    int denum;
    printf("Please enter the location you want to delect:");
    scanf("%d", &denum);
    delectnum(head, denum);
    output(head);

    int loc;
    printf("Please enter the location you want to insert:");
    scanf("%d", &loc);
    head = insert(head, loc);
    output(head);

    return 0;
}
