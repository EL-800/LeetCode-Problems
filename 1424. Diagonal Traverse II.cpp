#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diagonals;
        for (int i = nums.size() - 1; i >= 0; i--){
            for (int j = nums[i].size() - 1; j >= 0; j--)
                diagonals[i + j].push_back(nums[i][j]);                        
        }
        vector<int> order;
        for (auto diagonal : diagonals)
            order.insert(order.end(), diagonal.second.begin(), diagonal.second.end());        
        return order;
    }
};

int main(){
    return 0;
}