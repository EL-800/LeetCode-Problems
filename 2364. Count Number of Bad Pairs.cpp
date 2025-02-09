#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, long long> valCount;
        for (int i = 0; i < n; i++) 
            valCount[nums[i] - i]++;
        long long ans = 0;
        for (auto val : valCount) 
            ans += val.second * (val.second - 1) / 2;
        return n * (n - 1) / 2 - ans;             
    }
};

int main() {
    return 0;
}