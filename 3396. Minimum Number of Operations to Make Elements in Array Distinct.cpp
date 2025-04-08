#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();            
            unordered_map<int, int> frequency;
            for (int i = 0; i < n; i++)                 
                frequency[nums[i]]++;                
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (!count_if(frequency.begin(), frequency.end(), [](const pair<int, int>& p) { return p.second > 1;}))
                    return ans;                    
                int m = i + 3;
                for (; i < m && i < n; i++)
                    frequency[nums[i]]--;   
                i--;                                                                 
                ans++;
            }
            return ans;
        }
    };

int main() {
    return 0;
}