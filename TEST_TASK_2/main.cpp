#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<int> A(10);
    vector<int> B(15);
    for (int & i : A) {
        i = rand();
        cout << i << ' ';
    }
    cout << "\n";
    for (int & i : B) {
        i = rand();
        cout << i << ' ';
    }
    vector<int> C(A.size() + B.size());
    int k = 0;
    for (int j : A) {
        C[k++] = j;
    }
    for (int j : B) {
        C[k++] = j;
    }
    sort(C.begin(), C.end());
    cout << "\n";
    for (int j : C) {
        cout << j << ' ';
    }
    cout << "\n";
    cout << C[0] << ' ';
    cout << C[C.size() - 1] << ' ';
    int res = 1;
    for (int l : C) {
        res *= l;
    }
    cout << pow(res, 1 / static_cast<double>(C.size()));
    return 0;
}
