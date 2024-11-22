#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        map<vector<int>, int> countRows;
        for (auto row : matrix) 
            countRows[row]++;        
        int ans = 0;
        for (auto [key, value] : countRows) {
            auto flippedKey = key;
            for (int i = 0; i < m; i++)
                flippedKey[i] = !key[i];
            ans = max(ans, value + countRows[flippedKey]);
        }
        return ans;
    }
};

int main() {
    return 0;
}