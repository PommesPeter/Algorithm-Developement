/* Title: mergesort_template
 * Author: @PommesPeter
 * Data:2021-02-05
 * */

#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], tmp[N];

void merge_sort(int q[], int l , int r) {
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    //归并的过程，先从这两个序列之中分别取出一个，然后进行比较，小的先放前面,i指向左半边起点，j是右半边启动
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    //把剩余没放完的放完
    while(i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    //把临时数组里面的数存回q序列
    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}