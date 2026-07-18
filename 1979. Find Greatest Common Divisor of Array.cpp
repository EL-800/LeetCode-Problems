#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = 0;
        for (int num : nums) {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        return __gcd(minNum, maxNum);
    }
};

int main() {
    return 0;
}