#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++)
                count += grid[i][j];            
            if (count > 1) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j])
                        grid[i][j] = 2;   
                }
                ans += count;
            }            
        }
        for (int i = 0; i < m; i++) {
            int totalCount = 0, validCount = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1)
                    validCount++;                
                totalCount += min(grid[j][i], 1);
            }    
            ans += totalCount > 1 ? validCount : 0;        
        }
        return ans;
    }
};

int main() {
    return 0;
}