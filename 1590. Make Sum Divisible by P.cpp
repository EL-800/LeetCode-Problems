#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remove = 0;
        for (int num : nums)
            remove = (remove + num) % p;        
        if (!remove)
            return 0;
        unordered_map<int, int> subCount;
        int curr = 0, ans = INT_MAX;
        subCount[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;   
            int remind = (curr - remove + p) % p;         
            if (subCount.count(remind))
                ans = min(ans, i - subCount[remind]);
            subCount[curr] = i;
        }
        return ans < nums.size() ? ans : -1;
    }
};

int main() {
    return 0;
}