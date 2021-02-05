/* Title: quicksort template
 * Author: @PommesPeter
 * Data: 2021-02-05
 * */

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    //一般取中间那个数是效率是最高的
    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    //这里i=l-1 j=r+1 是因为还没一开始程序还没开始的时候指针不能放到边界，因为此时还没开始比较，所以要放到区间的外面，这样每次循环都会从要比较的开始
    while (i < j) {
        do {
            i++;
        } while (q[i] < x);
        do {
            j--;
        } while (q[j] > x);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    //对当前左边界l到j的区间进行下一次快排
    quick_sort(q, l, j);
    //对j+1到当前右边界的区间进行快排
    quick_sort(q, j + 1, r);
    //另一种写法
    //x = q[r];
    //quicksort(q, l, i - 1);
    //quicksort(q, i, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}