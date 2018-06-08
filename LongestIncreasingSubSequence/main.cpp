#include <bits/stdc++.h>

using namespace std;

// Recursive
long lisRecursive(vector<int> arr, int i = -1) {
    if (i == -1) i = arr.size()-1;
    if (i == 0) return 1;
    if (arr[i] > arr[i-1]) return lisRecursive(arr, i-1) + 1;
    return lisRecursive(arr, i-1);
}

// Tabulation
long lisTabulation(vector<int> arr) {
    vector<int> table(arr.size(), 1);
    int i, j;
    for (i = 1; i < arr.size(); i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j])
                table[i] = table[j] + 1;
    return table[table.size()-1];
}

int main() {
    vector<int> arr = {1, 6, 2, 8, 3, 6, 4, 9};

    cout << lisRecursive(arr) << endl;
    cout << lisTabulation(arr) << endl;

    return 0;
}