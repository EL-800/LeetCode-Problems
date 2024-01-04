#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freqs;
        for (int num : nums)
            freqs[num]++;
        int operations = 0;
        for (auto freq : freqs){
            if (freq.second == 1)
                return -1;
            if (freq.second % 3 == 0)
                operations += freq.second / 3;
            else if (freq.second % 3 == 1)
                operations += (freq.second - 3) / 3 + 2;
            else
                operations += freq.second / 3 + 1;
        }
        return operations;
    }
};

int main(){
    return 0;
}