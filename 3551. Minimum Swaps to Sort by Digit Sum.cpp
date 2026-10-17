#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetDigitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sorted;
        for (int i = 0; i < n; i++) {
            int digitSum = GetDigitSum(nums[i]);
            sorted.push_back({digitSum, nums[i], i});
        }

        sort(sorted.begin(), sorted.end());

        int ans = 0;
        vector<bool> visited(n);        
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            int j = sorted[i][2];                    
            while (!visited[j]) {                                    
                visited[j] = true;                
                j = sorted[j][2];                
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}