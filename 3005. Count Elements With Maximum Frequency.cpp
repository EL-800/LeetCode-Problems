#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freqs(*max_element(nums.begin(), nums.end()) + 1);
        for (int num : nums)
            freqs[num]++;
        int maxE = *max_element(freqs.begin(), freqs.end());
        return count(freqs.begin(), freqs.end(), maxE) * maxE;
    }
};

int main(){
    return 0;
}