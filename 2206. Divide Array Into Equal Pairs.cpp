#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            bitset<501> numsCount;
            for (int num : nums) 
                numsCount.flip(num);            
            return numsCount.none();
        }
    };

int main() {
    return 0;
}