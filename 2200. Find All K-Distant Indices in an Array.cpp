#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {        
        int n = nums.size(); 
        vector<int> marked(n + 1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                marked[max(i - k, 0)]++;
                marked[min(i + k + 1, n)]--;
            }
        }
        int opens = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            opens += marked[i];
            if (opens)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}