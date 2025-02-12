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
        int maximumSum(vector<int>& nums) {
            unordered_map<int, int> bestValues;
            int ans = -1;
            for (int num : nums) {
                int digitSum = GetDigitSum(num);
                if (bestValues.count(digitSum))
                    ans = max(ans, bestValues[digitSum] + num);
                bestValues[digitSum] = max(bestValues[digitSum], num);
            }
            return ans;
        }
    };

int main() {
    return 0;
}