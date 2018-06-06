#include <bits/stdc++.h>

using namespace std;

struct LongestCommonSubSequence {
    string a, b;
    vector<vector<long>> grid;
    void calculate(string strA, string strB) {
        a = strA; b = strB;
        grid.resize(a.size()+1);
        for (auto &g : grid) g.resize(b.size()+1);
        int i, j;
        for (i=0; i<=a.size(); i++) {
            for (j=0; j<=b.size(); j++) {
                if (i == 0 || j == 0)
                    grid[i][j] = 0;
                else if (a[i-1] == b[j-1])
                    grid[i][j] = grid[i-1][j-1] + 1;
                else
                    grid[i][j] = max(grid[i][j-1], grid[i-1][j]);
            }
        }
    }
    long getLength() {
        return grid[a.size()][b.size()];
    }
    string getString() {
        int i = a.size(), j = b.size();
        string result;
        while (grid[i][j] != 0) {
            if (grid[i][j] == grid[i-1][j])
                i = i-1;
            else if (grid[i][j] == grid[i][j-1])
                j = j-1;
            else {
                result += a[i-1];
                i = i-1;
                j = j-1;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    string a = "AXYSZFD", b = "DAWESZFAWDQ";
    
    LongestCommonSubSequence lss;
    lss.calculate(a, b);
    auto length = lss.getLength();
    cout << length << endl;
    cout << lss.getString() << endl;
    return 0;
}