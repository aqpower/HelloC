#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 5000

typedef int Status;
typedef int KeyType;
typedef int InfoType;
typedef struct {
    KeyType key;
    InfoType otherinfo;
} RedType;
typedef struct {
    RedType* r;
    int length;
} SqList;

Status InitSqList(SqList*);
Status CreateSqList(SqList*);
Status CopySqList(SqList, SqList*);
Status OutputSqList(SqList);
int LT(KeyType, KeyType);
void Swap(RedType*, RedType*);
Status InsertSort(SqList&);
Status BInsertSort(SqList&);
Status ShellInsert(SqList&, int[], int);
Status ShellSort(SqList&);
Status BubbleSort(SqList&);
int Partition(SqList&, int, int); // 一趟快速排序
void QSort(SqList&, int, int);
Status QuickSort(SqList&);
Status SelectSort(SqList&);

int main() {
    SqList L, L_BAK;
    int select, flag = 1, t, dlta[MAXSIZE];
    double duration;
    clock_t start, finish;

    InitSqList(&L);
    InitSqList(&L_BAK);
    CreateSqList(&L_BAK);
    t = 0;
    dlta[0] = L_BAK.length / 2;
    while (dlta[t] > 1) {
        dlta[t + 1] = dlta[t] / 2;
        t++;
    }
    while (flag) {
        CopySqList(L_BAK, &L);
        printf("\nPlease select:\n");
        printf("1.InsertSort\n");
        printf("2.BInsertSort\n");
        printf("3.ShellSort\n");
        printf("4.BubbleSort\n");
        printf("5.QuickSort\n");
        printf("6.SelectSort\n");
        printf("7.HeapSort\n");
        printf("8.MergeSort\n");
        printf("9.Exit\n");
        scanf("%d", &select);
        switch (select) {
            case 1:
                printf("\nNow is in InsertSort ......\n");
                start = clock();
                InsertSort(L);
                finish = clock();
                break;
        }
        putchar('\n');
        OutputSqList(L);
        duration = (double)(finish - start) / CLK_TCK;
        printf("The Sort Spend:%lf seconds.\n", duration);
    }
    return 0;
}

Status InitSqList(SqList* L) {
    L->r = (RedType*)malloc((MAXSIZE + 1) * sizeof(RedType));
    if (!L->r) {
        exit(OVERFLOW);
    }
    L->length = 0;
    return OK;
}

Status CreateSqList(SqList* L) {
    int i;
    srand(time(NULL));
    printf("\nPlease Input the Number of UnSorted Data: ");
    scanf("%d", &L->length);
    for (int i = 1; i <= L->length; i++) {
        L->r[i].key = rand();
    }
    printf("\nThe UnSorted Data is:\n");
    for (int i = 1; i <= L->length; i++) {
        printf("%8d", L->r[i].key);
    }
    putchar('\n');
    return OK;
}

Status CopySqList(SqList L_BAK, SqList* L) {
    int i;
    if (!L_BAK.length) {
        printf("The SqList is Empty!\n");
        return ERROR;
    }
    for (i = 1; i <= L_BAK.length; i++) {
        L->r[i].key = L_BAK.r[i].key;
    }
    L->length = L_BAK.length;
    return OK;
}

Status OutputSqList(SqList L) {
    int i;
    printf("The Length of SqList is %d.\n", L.length);
    printf("The Sorted Data is:\n");
    for (i = 1; i <= L.length; i++) {
        printf("%8d", L.r[i].key);
    }
    putchar('\n');
    return OK;
}

// Less Then
int LT(KeyType e1, KeyType e2) {
    if (e1 < e2) {
        return 1;
    } else {
        return 0;
    }
}

void Swap(RedType* e1, RedType* e2) {
    RedType e;
    e = *e1;
    *e1 = *e2;
    *e2 = e;
}

Status InsertSort(SqList& L) {
    for (int i = 2; i <= L.length; i++) {
        L.r[0].key = L.r[i].key;
        int ind = i - 1;
        while (L.r[i].key < L.r[ind].key) {
            ind--;
        }
        for (int j = ind + 1; j < i; j++) {
            L.r[j].key = L.r[j + 1].key;
        }
        L.r[ind + 1].key = L.r[0].key;
    }
    return OK;
}