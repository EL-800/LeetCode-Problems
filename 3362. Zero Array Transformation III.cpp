#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), opens = 0, queryInd = 0, used = 0;
        vector<int> close(n + 1);
        priority_queue<int> closingQueries;
        sort(queries.begin(), queries.end());                
        for (int i = 0; i < n; i++) {
            while (queryInd < m && i >= queries[queryInd][0]) {
                closingQueries.push(queries[queryInd][1]);                
                queryInd++;
            }
            opens -= close[i];
            while (opens < nums[i]) {
                if (closingQueries.empty())
                    return -1;
                int latestClose = closingQueries.top();
                closingQueries.pop();
                if (latestClose < i)
                    return -1;
                opens++;
                close[latestClose + 1]++;
                used++;
            }
        }
        return m - used;
    }
};

int main() {
    return 0;
}