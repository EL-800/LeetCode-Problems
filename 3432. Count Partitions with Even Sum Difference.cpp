#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int currParity = 0;
        for (int num : nums) 
            currParity = (currParity + num) % 2;        
        return ((int)nums.size() - 1) * (currParity == 0);
    }
};

int main() {
    return 0;
}