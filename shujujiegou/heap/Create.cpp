#include <iostream>
using namespace std;
const int maxn = 100;
int heap[maxn], n = 10;

// todo adjust from low to high
// ! low is the index you want to adjust, high is the index of the end of the heap
void downAdjust(int low, int high)
{
    int i = low, j = low * 2;
    while (j <= high)
    {
        if (j + 1 <= high && heap[j + 1] > heap[j])
        {
            j = j + 1;
        }
        if (heap[j] > heap[i])
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
}
// todo adjust from low to high
// ! low always be 1, high is the index you want to adjust
void upAdjust(int low, int high)
{
    int i = high, j = i / 2;
    while (j >= low)
    {
        if (heap[j] < heap[i])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }
        else
        {
            break;
        }
    }
}
void Createheap()
{
    for (int i = n / 2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
}
void deleteTop()
{
    heap[1] = heap[n--];
    downAdjust(1, n);
}
void insert(int x)
{
    heap[++n] = x;
    upAdjust(1, n);
}

void heapSort()
{
    Createheap();
    for (int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1); // todo  adjust the top
    }
}

void down(int low, int high){
    int i = low, j = i * 2;
    while(j <= high){
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[i] < heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> heap[i];
    }
    heapSort();
    reverse(heap + 1, heap + n + 1);
    for (int i = 1; i <= n;i++){
        cout << heap[i] << ' ';
    }
    return 0;
}
