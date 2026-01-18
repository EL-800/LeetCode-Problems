#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool isValid(vector<vector<int>>& grid, int i, int j, int k) {
        int totalSum = 0, currSum = 0;
        
        for (int diagonal = 0; diagonal < k; diagonal++) 
            currSum += grid[i + diagonal][j + diagonal];
        totalSum = currSum;

        currSum = 0;
        for (int diagonal = 0; diagonal < k; diagonal++) 
            currSum += grid[i + diagonal][j + k - 1 - diagonal];
        if (totalSum != currSum) 
            return false;

        for (int row = i; row < i + k; row++) {
            currSum = 0;
            for (int col = j; col < j + k; col++) 
                currSum += grid[row][col];            
            if (totalSum != currSum) 
                return false;
        }

        for (int col = j; col < j + k; col++) {
            currSum = 0;
            for (int row = i; row < i + k; row++) 
                currSum += grid[row][col];
            if (totalSum != currSum) 
                return false;
        }
        
        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 1;

        for (int k = 2; k <= min(n, m); k++) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    if (isValid(grid, i, j, k)) 
                        res = k;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}