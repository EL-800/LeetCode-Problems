#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * 1ll) * (*min_element(nums.begin(), nums.end()) * 1ll);
    }
};

int main() {
    return 0;
}