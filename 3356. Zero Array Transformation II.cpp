#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        const int maxSweepValue = 5e5;

        bool IsPossible(vector<int>& nums, vector<vector<int>>& queries, int k) {
            int n = nums.size();
            vector<long long> sweepLine(n + 1);
            for (int i = 0; i <= k; i++) {
                int beg = queries[i][0], end = queries[i][1], val = queries[i][2]; 
                sweepLine[beg] += val;
                sweepLine[end + 1] -= val;
            }
            long long currVal = 0;
            for (int i = 0; i < n; i++) {
                currVal += sweepLine[i];
                if (currVal < nums[i])
                    return false;
            }
            return true;
        }

    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int left = 0, right = queries.size();
            if (count(nums.begin(), nums.end(), 0) == nums.size())
                return 0;
            while (left < right) {
                int mid = (left + right) / 2;
                if (mid < queries.size() && IsPossible(nums, queries, mid))
                    right = mid;
                else
                    left = mid + 1;
            }
            return left < queries.size() ? left + 1 : -1;
        }
    };

int main() {
    vector<int> a = {5};
    vector<vector<int>> b = {{0,0,5},{0,0,1},{0,0,3},{0,0,2}};
    Solution s;
    cout << s.minZeroArray(a, b);
    return 0;
}