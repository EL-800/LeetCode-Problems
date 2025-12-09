#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, int> leftValues, rightValues;
        for (int i = 2; i < n; i++) 
            rightValues[nums[i]]++;

        int ans = 0;
        leftValues[nums[0]]++;
        for (int i = 1; i < n - 1; i++) {
            int pivot = nums[i] * 2;
            long long add = ((long long)leftValues[pivot] * (long long)rightValues[pivot]) % mod;
            ans = (ans + add) % mod;
            rightValues[nums[i + 1]]--;
            leftValues[nums[i]]++;
        }

        return ans % mod;
    }
};

int main() {
    return 0;
}