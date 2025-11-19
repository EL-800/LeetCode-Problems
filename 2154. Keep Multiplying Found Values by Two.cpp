#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {        
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (num == original)
                original *= 2;
            else if (num > original)
                break;
        }

        return original;
    }
};

int main() {
    return 0;
}