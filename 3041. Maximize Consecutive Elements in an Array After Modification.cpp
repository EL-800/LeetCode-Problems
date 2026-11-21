#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size(), ans = 1, size = 1, curr = nums[0], last = -1;
        sort(nums.begin(), nums.end());        
                
        for (int i = 1; i < n; i++) {
            if (curr == nums[i]) {
                nums[i]++;
                last = i;
            }
            if (nums[i] == curr + 1) {
                size++;
                curr++;
            } 
            else if (curr < nums[i]) {
                size = 1;
                if (curr + 2 == nums[i] && i - 1 != last && (last == -1 || nums[last] != curr)) {
                    size++;
                    int j = i - 2;
                    while (j > -1 && j != last && curr == nums[j] + 1) {
                        curr--;
                        size++; 
                        j--;                         
                    } 
                } 
                curr = nums[i];
            }

            ans = max(ans, size);
        }
        
        return ans;
    }
};

int main() {
    return 0;
}