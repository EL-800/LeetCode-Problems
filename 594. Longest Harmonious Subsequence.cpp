#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) 
            freq[num]++;

        int ans = 0;
        for (auto [ind, val] : freq) 
            ans = max(ans, freq.count(ind - 1) ? freq[ind - 1] + val : 0);        
        return ans;
    }
};

int main() {
    return 0;
}