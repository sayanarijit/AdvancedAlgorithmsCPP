#include <bits/stdc++.h>

using namespace std;

long getWaysToScore(long target, vector<int> options) {
    vector<long> table(target+1, 0);
    table[0] = 1;
    for (int o : options)
        for (int i = o; i < table.size(); i++)
            table[i] += table[i-o];
    return table[target];
}

int main() {
    long target = 13;
    vector<int> options = { 3, 5, 10 };
    long ways = getWaysToScore(target, options);
    cout << ways << endl;
    return 0;
}