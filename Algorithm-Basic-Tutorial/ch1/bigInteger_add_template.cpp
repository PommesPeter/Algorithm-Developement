/* Title: mergesort_template
 * Author: @PommesPeter
 * Data:2021-02-07
 * */

#include <iostream>
#include <vector>
using namespace std;

vector<int> add (vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size())  t += A[i];
        if (i < B.size())  t += B[i]; //t存的是A[i] + B[i] + 上一位的余数
        C.push_back(t % 10);
        t /= 10;
    }
}

int main() {

    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    cout << a << " " << b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}