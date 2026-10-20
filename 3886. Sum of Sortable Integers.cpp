#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool IsValid(vector<int>& nums, int k) {
        int n = nums.size(), prevMax = 0, ind = 0;

        for (int i = 0; i < n; i += k) {
            int count = 0, mini = nums[i], maxi = nums[i];

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] > nums[j + 1])
                    count++;
                mini = min(mini, nums[j + 1]);
                maxi = max(maxi, nums[j + 1]);
            }

            if (nums[i + k - 1] > nums[i])
                count++;
            if (count > 1 || prevMax > mini)
                return false;

            prevMax = maxi;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0) {
                if (IsValid(nums, k))
                    ans += k;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}