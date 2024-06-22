#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {        
        int n = nums.size(), ans = 0, left = 0, right = 0;     
        queue<int> oddInd;  
        while (right < n) {
            if (nums[right] % 2)
                oddInd.push(right);                        
            while (left <= right && oddInd.size() > k) {
                if (nums[left] % 2)
                    oddInd.pop();                                        
                left++;
            }
            if (oddInd.size() == k)
                ans += oddInd.front() - left + 1;
            right++;                                 
        }
        return ans;
    }
};

int main() {
    vector<int> c = {1,1,2,1,1};    
    Solution s;    
    cout << s.numberOfSubarrays(c, 3);
    return 0;
}