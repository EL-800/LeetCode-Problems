#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rowCount(n), colCount(m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                rowCount[i] += mat[i][j];
                colCount[j] += mat[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] && rowCount[i] == 1 && colCount[j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}