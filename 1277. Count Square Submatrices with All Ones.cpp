#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(); 
        vector<vector<int>> oneIndexed(n + 1, vector<int>(m + 1));                       
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) 
                oneIndexed[i][j] = matrix[i - 1][j - 1] + oneIndexed[i - 1][j] + oneIndexed[i][j - 1] - oneIndexed[i - 1][j - 1];                
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int size = 0; i + size <= n && j + size <= m; size++) {
                    int sum = oneIndexed[i + size][j + size] - oneIndexed[i - 1][j + size] - oneIndexed[i + size][j - 1] + oneIndexed[i - 1][j - 1];                    
                    if ((size + 1) * (size + 1) == sum)
                        ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}