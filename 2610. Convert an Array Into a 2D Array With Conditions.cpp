#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int row = 0;
        vector<vector<int>> matrix(1, vector<int>());
        for (int num : nums){
            if (matrix[row].empty()) {
                matrix[row].push_back(num);
                continue;
            }
            else if (matrix[row].back() == num) {
                row++;
                if (row >= matrix.size())
                    matrix.push_back(vector<int>());                
            }
            else 
                row = 0;                                            
            matrix[row].push_back(num);
        }
        return matrix;
    }
};

int main(){
    return 0;
}