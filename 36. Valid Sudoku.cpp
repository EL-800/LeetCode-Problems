#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> cube;
            for (int j = 0; j < 9; j++){
                if(board[i][j]!='.' && !row.insert(board[i][j]).second)
                    return false;
                if(board[j][i]!='.' && !col.insert(board[j][i]).second)
                    return false;
                int RowIndex = 3*(i/3);
                int ColIndex = 3*(i%3);
                if(board[RowIndex + j/3][ColIndex + j%3]!='.' && !cube.insert(board[RowIndex + j/3][ColIndex + j%3]).second)
                    return false;
            }
        }
        return true;
    }
};

int main() {    
    return 0;
}