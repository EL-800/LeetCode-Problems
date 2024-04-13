#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> peaks;
        int n = (int)height.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            while (!peaks.empty() && height[i] > height[peaks.top()]) {
                int h = peaks.top();
                peaks.pop();
                if (peaks.empty())
                    break;
                int heightF = min(height[i], height[peaks.top()]);
                int d = i - peaks.top() - 1;
                ans += (heightF - height[h]) * d;
            }
            peaks.push(i);
        }
        return ans;
    }
};

int main(){
    return 0;
}