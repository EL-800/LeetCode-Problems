#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int, int>> rowsLimit(n + 1, {INT_MAX, INT_MIN}), colsLimit(n + 1, {INT_MAX, INT_MIN});
        for (auto point : buildings) {
            int row = point[0], col = point[1];
            rowsLimit[row].first = min(rowsLimit[row].first, col);
            rowsLimit[row].second = max(rowsLimit[row].second, col);
            colsLimit[col].first = min(colsLimit[col].first, row);
            colsLimit[col].second = max(colsLimit[col].second, row);
        }            

        int ans = 0;
        for (auto point : buildings) {
            int row = point[0], col = point[1];
            if (rowsLimit[row].first == INT_MAX || rowsLimit[row].second == INT_MIN)
                continue;
            if (colsLimit[col].first == INT_MAX || colsLimit[col].second == INT_MIN)
                continue;
            if (rowsLimit[row].first == col || rowsLimit[row].second == col)
                continue;
            if (colsLimit[col].first == row || colsLimit[col].second == row)
                continue;
            ans++;
        }

        return ans;
    }
};

int main() {
    return 0;
}