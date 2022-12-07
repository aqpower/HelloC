int strcmp(char *str1, char *str2)
{
    while (*str1 && *str1 == *str2)
        str1++, str2++;
    return *str1 - *str2;
}
void main()
{
    printf("%d\n", strcmp("abc", "abe"));
}

// 1 f aa 2 m bb 3 m cc - 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TLink
{
    int num;
    char sex[20];
    char name[30];
    struct TLink *next;
} STU;
void print(STU *h)
{
    printf("%d\t%s\t%s\n", h->num, h->sex, h->name);
}
void scan(STU *h)
{
    scanf("%d%s%s", &h->num, h->sex, h->name);
}
void create(STU *h)
{
    int num;
    STU *p, *q = h;
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
        if (h->num == num)
            return h;
    }
    return NULL;
}
STU *findname(STU *h, char *name)
{
    while (h = h->next, h)
    {
        if (!strcmp(h->name, name))
            return h;
    }
    return NULL;
}
void deletenum(STU *h, int num)
{
    STU *p = h->next;
    while (p && p->num != num)
    {
        h = p, p = p->next;
    }
    if (p)
    {
        h->next = p->next;
        free(p);
    }
}
void deletename(STU *h, char *name)
{
    STU *p = h->next;
    while (p && strcmp(p->name, name))
    {
        h = p, p = p->next;
    }
    if (p)
    {
        h->next = p->next;
        free(p);
    }
}
void insert(STU *h, STU *node, int num)
{
    STU *pos = findnum(h, num);
    if (!pos)
    {
        while (h->next != NULL)
            h = h->next;
        pos = h;
    }
    node->next = pos->next;
    pos->next = node;
}

void main()
{
    STU *head = (STU *)malloc(sizeof(STU));
    int n;
    STU *node = (STU *)malloc(sizeof(STU));
    create(head);
    output(head);

    STU *temp = findnum(head, n);
    if (temp)
        print(temp);
    deletenum(head, n);
    printf("输入节点数据:\n");
    scan(node);
    printf("input num:");
    scanf("%d", &n);
    insert(head, node, n);
    output(head);
}
