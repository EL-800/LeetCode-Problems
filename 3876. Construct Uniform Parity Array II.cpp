#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0, minNum = INT_MAX;

        for (int num : nums1) {
            oddCount += num % 2;
            minNum = min(minNum, num);
        }

        return minNum % 2 || oddCount == 0;
    }
};

int main() {
    return 0;
}