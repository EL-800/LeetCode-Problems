#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {        
        unordered_set<int> bucket;        
        for (int num : nums)
            bucket.insert(num);
        const int maxNumber = 317;
        int ans = 0;
        for (int num : nums) {
            int currCount = 1;
            while (num <= maxNumber && bucket.count(num * num)) {
                num *= num;
                currCount++;
            }
            ans = max(ans, currCount);
        }
        return ans == 1 ? -1 : ans;
    }
};

int main() {
    return 0;
}