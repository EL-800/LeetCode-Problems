#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> groups;
            for (int i = 1; i <= n; i++) {
                int digitSum = 0, num = i;
                while (num) {
                    digitSum += num % 10;
                    num /= 10;
                }
                groups[digitSum]++;
            }
            int maxVal = 0, count = 0;
            for (auto [key, val] : groups) {
                if (val > maxVal) {
                    count = 1;
                    maxVal = val;
                }
                else if (val == maxVal)
                    count++;                
            }
            return count;
        }
    };

int main() {
    return 0;
}