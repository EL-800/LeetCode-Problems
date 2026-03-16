#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), limitSize = 3;        
        set<int> bestsRhombus;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bestsRhombus.insert(grid[i][j]);                

                int k = 1;
                while (true) {
                    int r = i + 2 * k;
                    int left = j - k;
                    int right = j + k;

                    if(r >= n || left < 0 || right >= m) 
                        break;

                    int sum = 0;
                    int currRow = i, currCol = j;
                    for(int move = 0; move < k; move++) 
                        sum += grid[currRow + move][currCol + move];                    
                    
                    for(int move = 0; move < k; move++) 
                        sum += grid[currRow + k + move][currCol + k - move];                    
                    
                    for(int move = 0; move < k; move++) 
                        sum += grid[currRow + 2 * k - move][currCol - move];                    
                    
                    for(int move = 0; move < k; move++) 
                        sum += grid[currRow + k - move][currCol - k + move];                    

                    bestsRhombus.insert(sum);                    

                    k++;
                }
            }
        }

        vector<int> ans;
        for(auto it = bestsRhombus.rbegin(); it != bestsRhombus.rend() && ans.size() < 3; it++) 
            ans.push_back(*it);        

        return ans;
    }
};

int main() {
    return 0;
}