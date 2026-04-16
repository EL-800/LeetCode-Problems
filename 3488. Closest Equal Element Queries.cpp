#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;

    int GetLeft(vector<int> &indexes, int ind) {
        if (!ind)
            return n - *indexes.rbegin() + indexes[ind];
        return indexes[ind] - indexes[ind - 1];
    }

    int GetRight(vector<int> &indexes, int ind) {
        if (ind == indexes.size() - 1)
            return n - indexes[ind] + *indexes.begin();
        return indexes[ind + 1] - indexes[ind];
    }

public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        n = nums.size();
        unordered_map<int, vector<int>> numsInd;

        for (int i = 0; i < n; i++)
            numsInd[nums[i]].push_back(i);

        vector<int> ans;
        for (int ind : queries) {
            int num = nums[ind];
            if (numsInd[num].size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int localInd = lower_bound(numsInd[num].begin(), numsInd[num].end(), ind) - numsInd[num].begin();
            ans.push_back(min(GetLeft(numsInd[num], localInd), GetRight(numsInd[num], localInd)));
        }

        return ans;
    }
};

int main() {
    return 0;
}