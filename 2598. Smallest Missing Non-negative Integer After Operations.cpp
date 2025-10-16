#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freqCount;

        for (int num : nums) {
            int modVal = (num % value + value) % value;
            freqCount[modVal]++;                
        }

        for (int i = 0; i < nums.size() + 2; i++) {
            if (!freqCount[i % value])
                return i;
            freqCount[i % value]--;
        }
        return 800;
    }
};

int main() {

}