#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int BS(vector<int>& column, int beg){
        int end = column.size() - 1;
        while (beg < end){
            int mid = (beg + end) / 2 + 1;
            if (column[mid] - column[beg] == mid - beg)
                beg = mid;
            else
                end = mid - 1;
        }
        return beg;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> rowPrefix(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!j)
                    rowPrefix[i][j] = matrix[i][j] - '0';                
                else
                    rowPrefix[i][j] = matrix[i][j] - '0' + rowPrefix[i][j - 1];
            }
        }
        int maxArea = 0;
        for (int yBeg = 0; yBeg < n; yBeg++){
            for (int xBeg = 0; xBeg < m; xBeg++){
                if (matrix[yBeg][xBeg] == '0')
                    continue;
                int lowestRow = INT_MAX;
                for (int yEnd = yBeg; yEnd < n; yEnd++){
                    if (matrix[yEnd][xBeg] == '0')
                        break;
                    int xEnd = BS(rowPrefix[yEnd], xBeg);
                    lowestRow = min(xEnd, lowestRow);
                    maxArea = max(maxArea, (yEnd - yBeg + 1) * (lowestRow - xBeg + 1));
                }
            }
        }
        return maxArea;
    }
};

int main(){
    vector<vector<char>> c = {{'0', '1'},{'1', '0'}};
    Solution s;
    cout << s.maximalRectangle(c);
    return 0;
}