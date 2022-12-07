#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Trie
{
    int cnt;
    bool isend;
    struct Trie *children[26];
};
Trie *trieCreate()
{
    Trie *ret = (Trie *)malloc(sizeof(Trie));
    ret->cnt = 0;
    ret->isend = false;
    memset(ret->children, 0, sizeof(ret->children));
    return ret;
}
void trieInsert(Trie *obj, char *word)
{
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        int ch = word[i] - 'a';
        if (obj->children[ch] == NULL)
        {
            obj->children[ch] = trieCreate();
        }
        obj = obj->children[ch];
    }
    obj->cnt++;
    obj->isend = true;
}
int cntSearch(Trie *obj, char *word)
{
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        int ch = word[i] - 'a';
        if (obj->children[ch] == NULL)
        {
            return false;
        }
        obj = obj->children[ch];
    }
    return obj->cnt;
}
int main()
{
    int n, cas;
    char act, word[250];
    cin >> n;
    getchar();
    Trie *fir = trieCreate();
    while (n--)
    {
        scanf("%c %s", &act, word);
        getchar();
        if (act == 'I')
        {
            trieInsert(fir, word);
        }
        else
        {
            cas = cntSearch(fir, word);
            cout << cas << endl;
        }
    }

    return 0;
}