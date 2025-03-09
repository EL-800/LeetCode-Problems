#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.length(), left = 0, right = 0, countW = 0;
            while (right < k) {
                countW += blocks[right] == 'W';
                right++;
            }
            int ans = countW;
            while (right < n) {
                countW -= blocks[left] == 'W';
                countW += blocks[right] == 'W';
                ans = min(ans, countW);
                left++;
                right++;
            }
            return ans;                 
        }
    };

int main() {
    Solution s;
    s.minimumRecolors("WBBWWBBWBW", 7);
    return 0;
}