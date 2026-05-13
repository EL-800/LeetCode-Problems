#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diffs(2 * limit + 2);

        for(int i = 0; i < n / 2; i++){
            int left = nums[i], right = nums[n - i - 1];            
            if(left > right) 
                swap(left, right);                        
            
            diffs[2] += 2;
            diffs[2 * limit + 1] -= 2;
            
            int leftOne = left + 1, rightOne = right + limit + 1;
            diffs[leftOne] -= 1;
            diffs[rightOne] += 1;
            
            int sum = left + right;
            diffs[sum] -= 1;
            diffs[sum + 1] += 1;
        }

        int ans = INT_MAX, curr = 0;        

        for(int i = 2; i <= 2 * limit; i++){
            curr += diffs[i];
            ans = min(ans, curr);
        }

        return ans;
    }
};

int main() {
    return 0;
}