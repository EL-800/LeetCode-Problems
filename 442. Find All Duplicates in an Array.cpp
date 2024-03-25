#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {        
        int n = nums.size();
        if (n == 1)
            return vector<int>();
        sort(nums.begin(), nums.end());
        vector<int> duplicateds;
        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i - 1])
                duplicateds.push_back(nums[i]);
        }
        return duplicateds;
    }
};

int main(){
    return 0;
}