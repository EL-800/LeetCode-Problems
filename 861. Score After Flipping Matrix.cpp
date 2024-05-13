#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    int CheckRow(vector<int>& row){
        int number = 0, m = row.size();
        for (int i = 0; i < m; i++) {
            number <<= 1;
            number += row[i];        
        }            
        return number;
    }

    bool ChangeRow(vector<int>& row){
        int originalNumber = CheckRow(row), m = row.size();        
        vector<int> modifiedRow = row;
        for (int i = 0; i < m; i++)
            modifiedRow[i] ^= 1;
        int modifiedNumber = CheckRow(modifiedRow);
        if (modifiedNumber > originalNumber){
            row = modifiedRow;
            return true;
        }            
        return false;
    }

    bool ChangeCol(vector<vector<int>> & grid, int col){
        int count = 0, n = grid.size();
        for (int i = 0; i < n; i++)
            count += grid[i][col]; 
        if (count > (n - count))   
            return false;
        for (int i = 0; i < n; i++)
            grid[i][col] ^= 1; 
        return true;
    }

public:
    int matrixScore(vector<vector<int>>& grid) {
        bool change = false;
        do {
            for (int i = 0; i < grid.size(); i++){
                vector<int> row(grid[i].begin(), grid[i].end());
                if (ChangeRow(row)){
                    grid[i] = row;
                    change = true;
                }
            }
            for (int i = 0; i < grid[0].size(); i++)
                change |= ChangeCol(grid, i);    
            change = false;        
        } while (change);
        int total = 0;
        for (int i = 0; i < grid.size(); i++){
            total += CheckRow(grid[i]);
        } 
        return total;
    } 
};

int main(){
    vector<vector<int>> c = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    Solution s;
    s.matrixScore(c);
    return 0;
}