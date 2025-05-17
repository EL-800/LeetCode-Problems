#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = 3;
        vector<int> bucket(size);
        for (int num : nums)
            bucket[num]++;
        int ind = 0;
        for (int i = 0; i < size; i++) {
            while (bucket[i]--) {
                nums[ind] = i;
                ind++;
            }
        }        
    }
};

int main() {
    return 0;
}