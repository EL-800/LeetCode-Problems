#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeight = *max_element(height.begin(), height.end()), 
        left = 0, right = height.size() - 1, ans = 0;
        
        for (int i = 1; i <= maxHeight; i++) {
            while (height[left] < i) 
                left++;
            while (height[right] < i) 
                right--;
            ans = max(ans, (right - left) * i);
        }
        return ans;
    }
};

int main() {
    return 0;
}