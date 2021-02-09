/* Title: bigInteger_minus_template
 * Author: @PommesPeter
 * Data:2021-02-07
 * */

#include <iostream>
#include <vector>
using namespace std;
//判断两个数哪个大
bool cmp(vector<int> &A, vector<int> &B) {
    //A,B位数不相等那么哪个长就哪个数大
    if (A.size() != B.size())   return A.size() > B.size();
    //如果相等那么如果从最高位开始，如果A的最高位比B的最高位大那么说明A大
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])   return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        //做相减
        t = A[i] - t;
        if (i < B.size())   t -= B[i];
        //t>=0 为t本身，t<0 t=t+10;
        C.push_back((t + 10) % 10);
        //如果发生了需要借前一位来进行计算的时候此时A[i]-B[i]<0，所以t<0时，t=1
        //因为t=1之后在下一次循环计算的时候就会自动减1，否则就是t=0;
        if (t < 0)  t = 1;
        else t = 0;
    }
    //去除前导零C的最后一个元素是0（C.back()）
    while (C.size() > 1 && C.back() == 0)   C.pop_back();
    return C;
}

int main() {

    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    //A>B直接算，A<B加符号反过来再算
    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    } else {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    return 0;
}