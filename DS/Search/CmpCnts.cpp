// 随机生成5000个数，并分别用顺序查找和折半查找算法查找并统计查找次数。
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

// 顺序查找
int sequential_search(int numbers[], int size, int x) {
    int count = 0; // 计数器
    for (int i = 0; i < size; i++) {
        count++;
        if (numbers[i] == x) return count;
    }
    return -1;
}

// 折半查找
int binary_search(int numbers[], int size, int x) {
    int low = 0;
    int high = size - 1;
    int count = 0; // 计数器

    while (low <= high) {
        count++;
        int mid = (low + high) / 2;
        if (x == numbers[mid])
            return count;
        else if (x < numbers[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    // 随机生成5000个数
    const int size = 5000;
    int numbers[size];
    for (int i = 0; i < size; i++)
        numbers[i] = rand() % 10000 + 1; // [1, 10000]
    sort(numbers, numbers + size);       // 升序排序
    for (int i = 0; i < 5000; i += 777) {
        // 顺序查找
        int ind = numbers[i] = rand() % 5000;
        int x = numbers[ind]; // [1, 10000]
        int count1 = sequential_search(numbers, size, x);
        if (count1 == -1)
            cout << x << " not found" << endl;
        else
            cout << x << " 被找到了在 " << count1
                 << " 次顺序查找后" << endl;

        // 折半查找
        int count2 = binary_search(numbers, size, x);
        if (count2 == -1)
            cout << x << " not found" << endl;
        else
            cout << x << " 被找到了在 " << count2 << " 次折半查找后" << endl;
        cout << '\n';
    }

    return 0;
}
