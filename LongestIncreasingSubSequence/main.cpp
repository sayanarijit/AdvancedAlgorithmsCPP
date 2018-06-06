#include <bits/stdc++.h>

using namespace std;

long longestIncreasingSubSequence(vector<int> arr) {
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

    long result = longestIncreasingSubSequence(arr);
    cout << result << endl;
    return 0;
}