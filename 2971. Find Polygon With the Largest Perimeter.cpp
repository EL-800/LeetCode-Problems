#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int> nums) {
        sort(nums.begin(), nums.end());
        long long currSum = 0, best = -1;        
        for (int i = 0; i < nums.size(); i++) {                                                    
            if (currSum > nums[i])
                best = max(best, currSum + nums[i]);                                                            
            currSum += nums[i];    
        }
        return best;
    }
};

int main(){
    vector<int> c = {1,12,1,2,5,50,3};
    Solution s;
    s.largestPerimeter(c);
    return 0;
}