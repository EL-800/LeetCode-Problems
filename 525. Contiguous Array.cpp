#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> subDiff;
        int zeros = 0, ones = 0, ans = 0;
        subDiff[0] = -1;
        for (int i = 0; i < nums.size(); i++){
            nums[i] ? ones++ : zeros++;
            if (subDiff.count(ones - zeros))
                ans = max(ans, i - subDiff[ones - zeros]);
            else
                subDiff[ones - zeros] = i;
        }
        return ans;
    }    
};

int main(){
    return 0;
}