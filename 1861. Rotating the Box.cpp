#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> rotatedBox(m, vector<char>(n));
        for (int i = 0; i < n; i++) {            
            for (int j = 0; j < m; j++) {                
                rotatedBox[j][n - i - 1] = box[i][j];            
            }
        }        
        for (int i = 0; i < n; i++) {
            for (int j = m - 2; j >= 0; j--) {
                int aux = j;
                while (aux < m - 1 && rotatedBox[aux][i] == '#' && rotatedBox[aux + 1][i] == '.') {
                    swap(rotatedBox[aux][i], rotatedBox[aux + 1][i]);
                    aux++;
                }
            }
        }
        return rotatedBox;
    }
};

int main() {
    return 0;
}