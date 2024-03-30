#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int CountsubarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> numsCount;
        int left = 0, right = 0, ans = 0;
        while (right < nums.size()){
            numsCount[nums[right]]++;            
            while (left <= right && numsCount.size() > k){
                numsCount[nums[left]]--;
                if (!numsCount[nums[left]])
                    numsCount.erase(nums[left]); 
                left++;               
            }
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return CountsubarraysWithKDistinct(nums, k) - CountsubarraysWithKDistinct(nums, k - 1);
    }
};

int main(){
    Solution s;
    vector<int> c = {1,2,1,2,3};
    cout << s.subarraysWithKDistinct(c, 2);
    return 0;
}