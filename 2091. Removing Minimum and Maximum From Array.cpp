#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), minInd = min_element(nums.begin(), nums.end()) - nums.begin(), 
        maxInd = max_element(nums.begin(), nums.end()) - nums.begin();
        return min({max(minInd, maxInd) + 1, n - min(minInd, maxInd), 
            min(minInd, maxInd) + 1 + (n - max(minInd, maxInd))});
    }
};

int main() {
    return 0;
}