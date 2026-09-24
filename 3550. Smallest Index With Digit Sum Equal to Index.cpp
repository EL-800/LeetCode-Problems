#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (GetDigitSum(nums[i]) == i)
                return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}