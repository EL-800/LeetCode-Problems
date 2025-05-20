#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sweepLine(n + 1);
        for (auto query : queries) {
            sweepLine[query[0]]++;
            sweepLine[query[1] + 1]--;
        }
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += sweepLine[i];
            if (currSum < nums[i])
                return false;
        }
        return true;                    
    }
};

int main() {
    return 0;
}