#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, remainder = 0;
        while (numBottles) {
            ans += numBottles;
            numBottles += remainder;
            remainder = numBottles % numExchange;
            numBottles /= numExchange;            
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.numWaterBottles(15, 4);
    return 0;
}