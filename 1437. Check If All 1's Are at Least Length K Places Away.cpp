#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), prev = -1, i = 0;
        for (; i < n; i++) {
            if (nums[i]) {
                prev = i;
                break;
            }
        }

        i++;
        for (; i < n; i++) {
            if (nums[i] && i - prev - 1 < k)
                return false;
            else if (nums[i])
                prev = i;
        }

        return true;
    }
};

int main() {
    return 0;
}