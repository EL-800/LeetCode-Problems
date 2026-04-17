#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetRev(int num) {
        int revNum = 0;
        while (num) {
            revNum *= 10;
            revNum += num % 10;
            num /= 10;
        }
        return revNum;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        unordered_map<int, int> seenNums;
        
        for (int i = n - 1; i >= 0; i--) {
            int revNum = GetRev(nums[i]);
            auto it = seenNums.find(revNum);
            if (it != seenNums.end()) 
                ans = min(ans, it->second - i);
            seenNums[nums[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}