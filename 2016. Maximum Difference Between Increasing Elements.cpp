#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minimum = INT_MAX, ans = 0;
        for (int num : nums) {
            ans = max(ans, num - minimum);
            minimum = min(minimum, num);
        }
        return ans ? ans : -1;
    }
};

int main() {
    return 0;
}