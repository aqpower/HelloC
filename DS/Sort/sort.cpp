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
Status ShellInsert(SqList&, int);
Status ShellSort(SqList&, int[], int);
Status BubbleSort(SqList&);
int Partition(SqList&, int, int); // 一趟快速排序
void QSort(SqList&, int, int); // 对L中的子序列L.r[low...high]进行快速排序
Status QuickSort(SqList&);
Status SelectSort(SqList&);
Status HeapAdujst(SqList&, int, int);
Status HeapSort(SqList&);
Status Merge(SqList&, int, int, int);
void MSort(SqList&, int);  // L[1...n]做一趟归并排序
Status MergeSort(SqList&); // L[1...n]自底向上归并排序

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
        scanf_s("%d", &select);
        switch (select) {
            case 1:
                printf("\nNow is in InsertSort ......\n");
                start = clock();
                InsertSort(L);
                finish = clock();
                break;
            case 2:
                printf("\nNow is in BInsertSort ......\n");
                start = clock();
                BInsertSort(L);
                finish = clock();
                break;
            case 3:
                printf("\nNow is in ShellSort ......\n");
                start = clock();
                ShellSort(L, dlta, t);
                finish = clock();
                break;
            case 4:
                printf("\nNow is in BubbleSort ......\n");
                start = clock();
                BubbleSort(L);
                finish = clock();
                break;
            case 5:
                printf("\nNow is in QuickSort ......\n");
                start = clock();
                QuickSort(L);
                finish = clock();
                break;
            case 6:
                printf("\nNow is in SelectSort ......\n");
                start = clock();
                SelectSort(L);
                finish = clock();
                break;
            case 7:
                printf("\nNow is in HeapSort ......\n");
                start = clock();
                HeapSort(L);
                finish = clock();
                break;
            case 8:
                printf("\nNow is in MergeSort ......\n");
                start = clock();
                MergeSort(L);
                finish = clock();
                break;

            case 9: printf("GoodBye!\n"); return 0;
        }
        putchar('\n');
        OutputSqList(L);
        duration = (double)(finish - start) / CLOCKS_PER_SEC * 1000;
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
    printf("Please Input the Number of UnSorted Data:");
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
        for (int j = i; j > ind; j--) {
            L.r[j].key = L.r[j - 1].key;
        }
        L.r[ind + 1].key = L.r[0].key;
    }
    return OK;
}

Status BInsertSort(SqList& L) {
    for (int i = 2; i <= L.length; i++) {
        L.r[0].key = L.r[i].key;
        int left = 0, right = i;
        while (left < right) {
            int mid = (left + right) / 2;
            if (L.r[mid].key == L.r[i].key) {
                left = mid + 1;
            } else if (L.r[mid].key > L.r[i].key) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // 此处left即为需要插入的位置
        for (int j = i; j > left; j--) {
            L.r[j].key = L.r[j - 1].key;
        }
        L.r[left].key = L.r[0].key;
    }
    return OK;
}

Status ShellInsert(SqList& L, int d) {
    for (int i = 1 + d; i <= L.length; i += d) {
        L.r[0].key = L.r[i].key;
        int ind = i - d;
        while (L.r[i].key < L.r[ind].key) {
            ind -= d;
        }
        for (int j = i; j > ind; j -= d) {
            L.r[j].key = L.r[j - d].key;
        }
        L.r[ind + d].key = L.r[0].key;
    }
    return OK;
}
Status ShellSort(SqList& L, int a[], int length) {
    for (int i = 0; i < length; i++) {
        ShellInsert(L, a[i]);
    }
    return OK;
}

Status BubbleSort(SqList& L) {
    for (int i = 1; i <= L.length - 1; i++) {
        for (int j = 1; j + 1 <= L.length - i + 1; j++) {
            if (L.r[j + 1].key < L.r[j].key) {
                Swap(&L.r[j + 1], &L.r[j]);
            }
        }
    }
    return OK;
}

// 一趟快速排序
int Partition(SqList& L, int i, int j) {
    int k = L.r[i].key;
    while (i < j) {
        while (i < j && L.r[j].key >= k) j--;
        if (i < j) L.r[i++] = L.r[j];
        while (i < j && L.r[i].key < k) i++;
        if (i < j) L.r[j--] = L.r[i];
    }
    return i;
}

// 对L中的子序列L.r[low...high]进行快速排序
void QSort(SqList& L, int low, int high) {
    if (low < high) {
        int i = Partition(L, low, high);
        L.r[i].key = L.r[low].key;
        QSort(L, low, i - 1);  // 排序k左边
        QSort(L, i + 1, high); // 排序k右边
    }
} // 对L中的子序列L.r[low...high]进行快速排序

Status QuickSort(SqList& L) {
    QSort(L, 1, L.length);
    return OK;
}
Status SelectSort(SqList& L) {
    int i, j, min;
    for (i = 1; i < L.length; i++) {
        min = i;
        for (j = i + 1; j <= L.length; j++) {
            if (LT(L.r[j].key, L.r[min].key)) min = j;
        }
        if (min != i) {
            Swap(&L.r[i], &L.r[min]);
        }
    }
    return OK;
}
// 使L[s...m]成大根堆
Status HeapAdujst(SqList& L, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子节点指标在范围内才做比较
        if (son + 1 <= end &&
            L.r[son].key < L.r[son + 1].key) // 先比较两个子节点大小，选择最大的
            son++;
        if (L.r[dad].key >
            L.r[son].key) // 如果父节点大于子节点代表调整完毕，直接跳出函数
            return OK;
        else { // 否则交换父子内容再继续子节点和孙节点比较
            Swap(&L.r[dad], &L.r[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
    return OK;
}
Status HeapSort(SqList& L) {
    int i;
    // 初始化，i从最后一个父节点开始调整
    for (i = L.length / 2 - 1; i >= 0; i--) HeapAdujst(L, i, L.length - 1);
    // 先将第一个元素和已排好元素前一位做交换，再从新调整，直到排序完毕
    for (i = L.length - 1; i > 0; i--) {
        Swap(&L.r[0], &L.r[i]);
        HeapAdujst(L, 0, i - 1);
    }
    return OK;
}
Status Merge(SqList& L, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    SqList L1;
    L1.r = (RedType*)malloc((high - low + 1) * sizeof(RedType));
    while (i <= mid && j <= high)
        L1.r[k++] = LT(L.r[i].key, L.r[j].key) ? L.r[i++] : L.r[j++];
    while (i <= mid) {
        L1.r[k++] = L.r[i++];
    }
    while (j <= high) {
        L1.r[k++] = L.r[j++];
    }
    for (k = 0, i = low; i <= high; k++, i++) {
        L.r[i].key = L1.r[k].key;
    }
    return OK;
}

void MSort(SqList& L, int len) {
    int i;
    for (i = 1; i + 2 * len - 1 <= L.length; i = i + 2 * len) {
        Merge(L, i, i + len - 1, i + 2 * len - 1);
    }
    if (i + len - 1 < L.length) {
        Merge(L, i, i + len - 1, L.length);
    }
} // L[1...n]做一趟归并排序
Status MergeSort(SqList& L) {
    int len;
    for (len = 1; len < L.length; len *= 2) {
        MSort(L, len);
    }
    return OK;
} // L[1...n]自底向上归并排序
