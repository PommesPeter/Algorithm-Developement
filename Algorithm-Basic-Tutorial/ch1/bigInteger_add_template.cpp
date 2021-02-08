/* Title: bigInteger_add_template
 * Author: @PommesPeter
 * Data:2021-02-07
 * */

#include <iostream>
#include <vector>
using namespace std;

//C = A + B
vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || i < B.size(); i++) {
        //每次算每一个位数都是三个数相加：A[i] + B[i] + 上一位的进位
        //不存在的位就看乘0
        //这里就是用t来存A[i] + B[i]的结果
        if (i < A.size())  t += A[i];
        if (i < B.size())  t += B[i]; //t存的是A[i] + B[i] + 上一位的余数
        C.push_back(t % 10);
        t /= 10;
    }

    if (t != 0) C.push_back(1);
    return C;
}

int main() {

    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.emplace_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.emplace_back(b[i] - '0');

    vector<int> C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C.at(i));

    return 0;
}