#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct addressBook
{
    char name[20];
    char num[20];
    struct addressBook *next;
} BOOK;

void scan(BOOK *node)
{
    scanf("%s%s", node->name, node->num);
}

void print(BOOK *h)
{
    printf("%s\t%s\n", h->name, h->num);
}

void output(BOOK *h)
{
    while (h)
    {
        print(h);
        h = h->next;
    }
}

void create(BOOK *h)
{
    BOOK *q, *p;
    char name[20];

    while (scanf("%s", name), strcmp(name, "-1"))
    {
        p = (BOOK *)malloc(sizeof(BOOK));
        strcpy(h->name, name);
        scanf("%s", h->num);
        h->next = p;
        q = h;
        h = h->next;
    }
    q->next = NULL;
    free(p);
}

int len(BOOK *h)
{
    int count = 0;
    while (h)
    {
        h = h->next;
        count++;
    }
    return count;
}

BOOK *insert(BOOK *head, int i)
{

    if (i < 1 || i > len(head) + 1)
    {
        printf("i值错误\n");
        return head;
    }
    BOOK *p, *pre = head;
    int j = 1;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    printf("please enter the date:\n");
    p = (BOOK *)malloc(sizeof(BOOK));
    scan(p);
    if (i == 1)
    {
        p->next = head;
        head = p;
        return head;
    }
    p->next = pre->next;
    pre->next = p;

    return head;
}

BOOK *mydelete(BOOK *head, int i)
{
    BOOK *p, *pre;
    int j = 1;
    if (!head || i < 1 || i > len(head))
        return head;
    if (i == 1)
    {
        p = head;
        head = head->next;
        free(p);
        return head;
    }
    pre = head;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (!pre)
        return head;
    else
    {
        p = pre->next;
        pre->next = p->next;
        if (p)
            free(p);
    }
    return head;
}

BOOK *findName(BOOK *h, char *target)
{
    while (h)
    {
        if (!strcmp(h->name, target))
            return h;
        h = h->next;
    }
    return NULL;
}

BOOK *findNum(BOOK *h, char *target)
{
    while (h)
    {
        if (!strcmp(h->num, target))
            return h;
        h = h->next;
    }
    return NULL;
}

int main()
{
    BOOK *head = (BOOK *)malloc(sizeof(BOOK));

    printf("Please enter the date:\n");
    create(head);
    output(head);

    int insertPosition;
    printf("Please enter the location you want to insert:\n");
    scanf("%d", &insertPosition);
    head = insert(head, insertPosition);
    output(head);

    int deletePosition;
    printf("Please enter the location you want to delete:\n");
    scanf("%d", &deletePosition);
    head = mydelete(head, deletePosition);
    output(head);

    char *searchnum;
    printf("Please enter the num you want to search:");
    scanf("%s", searchnum);
    BOOK *num = findNum(head, searchnum);
    if (num)
        print(num);
    else
        printf("This Data Does Not Exist\n");

    char searchname[20];
    printf("Please enter the name you want to search:");
    scanf("%s", searchname);
    BOOK *name = findName(head, searchname);
    if (name)
        print(name);
    else
        printf("This Data Does Not Exist\n");

    return 0;
}