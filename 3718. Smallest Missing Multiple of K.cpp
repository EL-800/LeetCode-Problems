#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int curr = k;
        for (int num : nums) {
            if (num == curr)
                curr += k;
            else if (num > curr)
                break;              
        }

        return curr;
    }
};

int main() {
    return 0;
}