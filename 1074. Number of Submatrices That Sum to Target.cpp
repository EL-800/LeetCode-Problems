#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cont = 0;
        for (int x1 = 0; x1 < n; x1++){
            for (int y1 = 0; y1 < m; y1++){
                int rowSum[105] = {0};                
                for (int x2 = x1; x2 < n; x2++){
                    int currSum = 0;
                    for (int y2 = y1; y2 < m; y2++){
                        rowSum[y2] += matrix[x2][y2];
                        currSum += rowSum[y2];
                        cont += currSum == target;
                    }
                }
            }
        }
        return cont;
    }
};

int main(){

}