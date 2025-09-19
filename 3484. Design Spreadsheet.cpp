#include <bits/stdc++.h>

using namespace std;

class Spreadsheet {
private:
    const int cols = 26;
    vector<vector<int>> sheet;

    pair<int, int> GetCoords(string cell) {        
        int row = stoi(cell.substr(1)), col = cell[0] - 'A';
        return {row, col};
    }

public:
    Spreadsheet(int rows) {
        sheet.assign(rows + 1, vector<int>(cols, 0));
    }
    
    void setCell(string cell, int value) {
        auto [row, col] = GetCoords(cell);
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = GetCoords(cell);
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        int plusPos = formula.find('+'), val1, val2;
        string cell1 = formula.substr(1, plusPos - 1), cell2 = formula.substr(plusPos + 1);
        if (cell1[0] >= 'A' && cell1[0] <= 'Z') {
            auto [row, col] = GetCoords(cell1);
            val1 = sheet[row][col];
        }        
        else 
            val1 = stoi(cell1);
        if (cell2[0] >= 'A' && cell2[0] <= 'Z') {
            auto [row, col] = GetCoords(cell2);
            val2 = sheet[row][col];
        }        
        else 
            val2 = stoi(cell2);
        return val1 + val2;
    }
};

int main() {
    return 0;
}