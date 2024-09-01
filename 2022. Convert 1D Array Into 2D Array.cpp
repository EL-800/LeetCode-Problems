#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (m * n != original.size())
            return ans;
        ans.assign(m, vector<int>(n));
        int originalInd = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                ans[i][j] = original[originalInd++];
        }
        return ans;
    }
};

int main() {
    return 0;
}