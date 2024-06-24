#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> openFlips;
        int totalFlips = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((!nums[i] && !(openFlips.size() % 2)) || (nums[i] && (openFlips.size() % 2))) {
                totalFlips++;
                openFlips.push(i + k - 1);
            }
            if (openFlips.front() == i)
                openFlips.pop();
        }
        return openFlips.empty() ? totalFlips : -1;
    }
};

int main(){
    return 0;
}