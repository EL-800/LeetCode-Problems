#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans(m);
        for (int i = 0; i < m; i++){
            vector<int> subNums;
            for (int j = l[i]; j <= r[i]; j++)
                subNums.push_back(nums[j]);
            sort(subNums.begin(), subNums.end());
            int diff = subNums[1] - subNums[0];
            ans[i] = true;
            for (int j = 1; j < subNums.size(); j++){
                if (subNums[j] - subNums[j - 1] != diff){
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}