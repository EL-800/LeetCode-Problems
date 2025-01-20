#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, int> indexes;
        int ans = INT_MAX;
        for (int i = 0; i < arr.size(); i++) 
            indexes[arr[i]] = i;
        for (int i = 0; i < n; i++) {
            int currMaxInd = 0;
            for (int j = 0; j < m; j++) 
                currMaxInd = max(currMaxInd, indexes[mat[i][j]]);                                         
            ans = min(ans, currMaxInd);
        }
        for (int i = 0; i < m; i++) {
            int currMaxInd = 0;
            for (int j = 0; j < n; j++) 
                currMaxInd = max(currMaxInd, indexes[mat[j][i]]);                                         
            ans = min(ans, currMaxInd);
        }
        return ans;        
    }
};

int main() {
    vector<int> a = {2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat = {{3,2,5},{1,4,6},{8,7,9}};
    Solution s;
    s.firstCompleteIndex(a, mat);
    return 0;
}