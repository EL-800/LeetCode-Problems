#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {            
            colors.insert(colors.end(), colors.begin(), colors.begin() + k - 1);
            int n = colors.size(), left = 0, right = 1, ans = 0;
            while (right < n) {
                if (colors[right] == colors[right - 1])
                    left = right;
                ans += right - left + 1 >= k;
                right++;
            }
            return ans;
        }
    };

int main() {
    return 0;
}