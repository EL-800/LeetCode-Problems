#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> numberCount;
        int left = 0, right = 0, ans = 0;
        while (right < nums.size()){            
            if (numberCount[nums[right]] >= k) {
                numberCount[nums[left]]--;     
                left++;
            }          
            else {
                ans = max(ans, right - left + 1);
                numberCount[nums[right]]++;
                right++;
            }            
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(){
    Solution s;
    vector<int> c = {1,2,3,1,2,3,1,2};
    cout << s.maxSubarrayLength(c, 2);
}