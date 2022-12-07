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

void print(STU *h)
{
    printf("%d\t%s\t%s\n", h->num, h->sex, h->name);
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
}

void output(STU *h)
{
    while (h = h->next, h != NULL)
        print(h);
}

STU *findnum(STU *h, int num)
{
    while (h = h->next, h)
    {
        if (h->num = num)
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
    STU *p = h, *q; //这样你就找不到他的上家啊。。。。双节点移动法吧
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

    char name[9];
    getchar();
    printf("Please enter the name you want you find:");
    gets(name);
    STU *loname = findname(head, name);
    if (loname)
        print(loname);

    int denum;
    scanf("%d", &denum);
    delectnum(head, denum);

    output(head);

    return 0;
}