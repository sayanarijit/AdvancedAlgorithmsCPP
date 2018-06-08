#include <bits/stdc++.h>

using namespace std;

string binRecursive(int n, string s = "") {
    if (n > 1)
        s += binRecursive(n/2);
    return s + to_string(n%2);
}

string binIterative(int n) {
    string result;
    for (unsigned i = 1 << 31; i > 0; i /= 2)
        result += (n&i) ? "1" : "0";
    int i = result[0];
    while (i == '0') {
        result.erase(result.begin());
        i = result[0];
    }
    return result;
}

int main() {
    int n = 10;

    cout << binRecursive(n) << endl;
    cout << binIterative(n) << endl;

    return 0;
}