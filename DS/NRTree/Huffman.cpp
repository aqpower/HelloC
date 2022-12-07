/*
根据给定的权值构建哈夫曼树，并实现哈夫曼编码和译码

Input:
8
ABCDEFGH
7 19 2 6 32 3 21 20
1010000010000100111100010110011010

*/
#include <iostream>
using namespace std;

typedef int TElemType;
typedef struct {
    TElemType weight;
    int parent;
    int lchild, rchild;
} Node, *HuffmanTree;

#define Max_Tree_SIZE 99
char dic[Max_Tree_SIZE];

void InitHuffmanTree(HuffmanTree& root, int n) {
    root = (HuffmanTree)malloc(sizeof(Node) * (2 * n));
    for (int i = 1; i <= n; i++) {
        cin >> root[i].weight;
        root[i].parent = root[i].lchild = root[i].rchild = 0;
    }
}

void Select(HuffmanTree root, int n, int& pos1, int& pos2) {
    int mi = 1e9;
    for (int i = 1; i < n; i++) {
        if (root[i].weight < mi && !root[i].parent) {
            mi = root[i].weight;
            pos1 = i;
        }
    }
    mi = 1e9;
    for (int i = 1; i < n; i++) {
        if (i == pos1) {
            continue;
        }
        if (root[i].weight < mi && !root[i].parent) {
            mi = root[i].weight;
            pos2 = i;
        }
    }
}

void BuildHuffmanTree(HuffmanTree& root, int n) {
    int pos1, pos2;
    for (int k = n + 1; k < 2 * n; k++) {
        root[k].parent = 0;
        Select(root, k, pos1, pos2);
        root[k].weight = root[pos1].weight + root[pos2].weight;
        root[k].lchild = pos1;
        root[k].rchild = pos2;
        root[pos1].parent = k;
        root[pos2].parent = k;
    }
}

string huff[Max_Tree_SIZE];
void ToHuffman(HuffmanTree root, int n) {
    for (int i = 1; i <= n; i++) {
        int p = root[i].parent;
        int now = i;
        while (p != 0) {
            if (now == root[p].lchild) {
                huff[i].insert(0, 1, '0');
            } else {
                huff[i].insert(0, 1, '1');
            }
            now = p;
            p = root[p].parent;
        }
    }
}

// n表示字符的个数1~n
string ToCode(string s, int n) {
    string res;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        temp += s[i];
        for (int i = 1; i <= n; i++) {
            if (huff[i] == temp) {
                res += dic[i];
                temp.clear();
            }
        }
    }
    return res;
}

int main() {
    int n;
    HuffmanTree root;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%c", &dic[i]);
    }
    InitHuffmanTree(root, n);
    BuildHuffmanTree(root, n);
    ToHuffman(root, n);
    cout << "Congratulations!" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << dic[i] << ": " << huff[i] << '\n';
    }
    cout << "Please enter the huffcode: ";
    string huffcode;
    cin >> huffcode;
    string res = ToCode(huffcode, n);
    cout << huffcode << " " << "change to char: ";
    cout << res << '\n';
    return 0;
}