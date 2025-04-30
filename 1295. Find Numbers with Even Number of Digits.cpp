#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int ans = 0;
            for (int num : nums)
                ans += ((int)log10((float)num) + 1) % 2 == 0;
            return ans;
        }
    };

int main() {
    return 0;
}