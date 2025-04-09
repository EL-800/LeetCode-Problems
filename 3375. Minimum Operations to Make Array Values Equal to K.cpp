#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int minElement = INT_MAX;
            unordered_set<int> diffElements;
            for (auto num : nums) {
                minElement = min(minElement, num);
                diffElements.insert(num);
            }
            if (minElement < k)
                return -1;
            return diffElements.size() + (minElement > k) - 1;
        }
    };

int main() {
    return 0;
}