#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int Search(vector<int>& nums, int k, unordered_map<int, int>& restritedNumbers, int ind = 0){
        if (ind == nums.size())
            return !restritedNumbers.empty();
        int ans = Search(nums, k, restritedNumbers, ind + 1);
        if (restritedNumbers[nums[ind]])
            return ans;
        restritedNumbers[nums[ind] + k]++;
        ans += Search(nums, k, restritedNumbers, ind + 1);
        restritedNumbers[nums[ind] + k]--;
        return ans;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> restritedNumbers;
        sort(nums.begin(), nums.end());
        return Search(nums, k, restritedNumbers);
    }
};

int main(){
    return 0;
}