#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int remove = INT_MAX, n = matrix.size(), negativeCount = 0;
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += abs(matrix[i][j]);
                remove = min(remove, abs(matrix[i][j]));   
                if (matrix[i][j] < 0) {                                     
                    negativeCount++;
                }
            }
        }
        return negativeCount % 2 ? totalSum + 2 * remove : totalSum;
    }
};

int main() {
    return 0;
}