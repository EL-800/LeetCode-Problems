#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), maxNum = *max_element(nums.begin(), nums.end());
        vector<pair<int, int>> divisorsCount(maxNum + 1);

        for (int i = 1; i <= maxNum; i++) 
            divisorsCount[i] = {2, i + 1};

        for (int i = 2; i <= maxNum / 2 + 1; i++) {
            for (int j = i * 2; j <= maxNum; j += i) {
                divisorsCount[j].first++;
                divisorsCount[j].second += i;                
            }
        }
        
        int ans = 0, numDiv = 4;
        for (int num : nums) {
            if (divisorsCount[num].first == numDiv)
                ans += divisorsCount[num].second;
        }

        return ans;
    }
};

int main() {
    return 0;
}