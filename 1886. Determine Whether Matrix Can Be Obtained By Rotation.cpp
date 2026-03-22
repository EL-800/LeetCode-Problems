#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for (int rot = 0; rot < 4; rot++) {
            if (mat == target) 
                return true;
            vector<vector<int>> aux(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    aux[j][n - i - 1] = mat[i][j];
            }                                
            mat = aux;
        }
        
        return false;
    }
};

int main() {
    return 0;
}