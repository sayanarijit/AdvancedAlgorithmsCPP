#include <bits/stdc++.h>

using namespace std;

// Tabulation
int waysToScoreTabulation(int target, vector<int> options) {
    vector<int> table(target+1, 0);
    table[0] = 1;
    for (int o : options)
        for (int i = o; i < table.size(); i++)
            table[i] += table[i-o];
    return table[target];
}

int main() {
    int target = 13;
    vector<int> options = { 3, 5, 10 };
    
    cout << waysToScoreTabulation(target, options) << endl;
    
    return 0;
}