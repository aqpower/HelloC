/*
实现哈希表的构造和查找算法
用除留余数法构造哈希函数，分别用一次探测再散列，二次探测再散列解决冲突
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int ElemType;
#define Hashmod 9
#define Hashsize 10

typedef struct HASHTABLE {
    ElemType *elem;
    int count = 0;
    int sizeindex = Hashsize;
    HASHTABLE() { elem = (ElemType *)malloc(sizeof(ElemType) * Hashsize); }
} HashTable;

HashTable hashA, hashB;
ElemType a[100];

int HashValue(int x) { return (x % Hashmod) % Hashsize; }

// 返回哈希值
void IndDetect(HashTable hash, int &ind, int time, int exp) {
    int e = time / 2;
    if (time % 2) {
        e++;
        ind += pow(e, exp);
    } else {
        ind -= pow(e, exp);
    }
    ind %= hash.sizeindex;
}

void HashInsert(HashTable &hash, int x, int exp) {
    if (hash.count + 1 == hash.sizeindex) {
        hash.elem = (ElemType *)realloc(hash.elem,
                                        sizeof(ElemType) * hash.sizeindex * 2);
        hash.sizeindex = hash.sizeindex * 2;
        for (int i = hash.sizeindex / 2; i < hash.sizeindex; i++) {
            hash.elem[i] = -1;
        }
    }
    int ind = HashValue(x);
    int t = 1;
    while (hash.elem[ind] != -1) {
        ind = HashValue(x);
        IndDetect(hash, ind, t++, exp);
    }
    hash.elem[ind] = x;
    hash.count++;
}

int HashSearch(HashTable hash, int x, int exp) {
    int ind = HashValue(x);
    int t = 1;
    while (hash.elem[ind] != x) {
        ind = HashValue(x);
        IndDetect(hash, ind, t++, exp);
        if (t > hash.count || hash.elem[ind] == -1) {
            return -1;
        }
    }
    return ind;
}

void PrintHashTable(HashTable hasht) {
    for (int i = 0; i < hasht.count; i++) {
        printf("%d ", hasht.elem[i]);
    }
    putchar('\n');
}

void init() {
    // 初始化AB两个哈希表
    for (int i = 0; i < hashA.sizeindex; i++) {
        hashA.elem[i] = -1;
        hashB.elem[i] = -1;
    }
    // 生成随机数数组
    for (int i = 0; i < 100; i++) {
        a[i] = rand() % 100 + 2;
    }
    for (int i = 0; i < 10; i++) {
        HashInsert(hashA, a[i], 1);
    }
    for (int i = 0; i < 10; i++) {
        HashInsert(hashB, a[i], 2);
    }
}

int main() {
    init();

    printf("使用一次探测再散列构造的哈希表:\n");
    PrintHashTable(hashA);
    printf("查找66的下标：");
    printf("%d\n", HashSearch(hashA, 66, 1));
    printf("查找30的下标：");
    printf("%d\n", HashSearch(hashA, 30, 1));
    putchar('\n');

    printf("使用二次探测再散列构造的哈希表:\n");
    PrintHashTable(hashB);
    printf("查找66的下标：");
    printf("%d\n", HashSearch(hashB, 66, 1));
    printf("查找30的下标：");
    printf("%d\n", HashSearch(hashB, 30, 1));

    return 0;
}