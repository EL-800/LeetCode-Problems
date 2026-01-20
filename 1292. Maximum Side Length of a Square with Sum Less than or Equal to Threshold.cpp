#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m, threshold;

    bool Valid(vector<vector<int>> prefixSum, int size) {        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - size + 1 < 0 || j - size + 1 < 0)
                    continue;
                int prevRow = (i - size >= 0) ? prefixSum[i - size][j] : 0;                
                int prevCol = (j - size >= 0) ? prefixSum[i][j - size] : 0;
                int removed = (i - size >= 0) && (j - size >= 0) ? prefixSum[i - size][j - size] : 0;
                int currSum  = prefixSum[i][j] - prevRow - prevCol + removed;
                if (currSum <= threshold)
                    return true;
            }                        
        }

        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size(), m = mat[0].size();
        this->threshold = threshold;

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int prevRow = i ? prefixSum[i - 1][j] : 0;
                int prevCol = j ? prefixSum[i][j - 1] : 0;
                int excess = (i && j) ? prefixSum[i - 1][j - 1] : 0;
                prefixSum[i][j] = mat[i][j] + prevRow + prevCol - excess;
            }
        }        

        int left = 0, right = min(n, m);
        while (left < right) {            
            int mid = (left + right) / 2 + 1;
            if (Valid(prefixSum, mid))
                left = mid;
            else
                right = mid - 1;
        }
        
        return left;
    }
};

int main() {
    return 0;
}