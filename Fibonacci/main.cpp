#include <bits/stdc++.h>

using namespace std;

long fibonacci(int x, int y, int n) {
    vector<long> result(n);
    result[0] = x; result[1] = y;
    for (int i = 2; i < n; i++) {
        result[i] = result[i-1] + result[i-2];
    }
    return result[n-1];
}

int main() {
    cout << fibonacci(1, 2, 5) << endl;
    return 0;
}