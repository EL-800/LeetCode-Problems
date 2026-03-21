#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int y, int x, int k) {
        for (int i = x; i < x + k; i++) {            
            for (int beg = y, end = y + k - 1; beg < end; beg++, end--) 
                swap(grid[beg][i], grid[end][i]);            
        }
        return grid;
    }
};

int main() {
    return 0;
}