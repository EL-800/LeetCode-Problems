#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> ranges;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
            ranges.push_back({ startTime[i], endTime[i], profit[i] });        
        sort(ranges.begin(), ranges.end());
        function<int(int)> Search;
        Search = [&](int i) -> int {
            if (i == n)
                return 0;
            if (dp[i])
                return dp[i];
            return dp[i] = max(Search(lower_bound(ranges.begin(), ranges.end(), ranges[i][1], [](const vector<int>& a, const int b) {
                return a[0] < b;
            }) - ranges.begin()) + ranges[i][2], Search(i + 1));
        };
        return Search(0);
    }
};

int main(){
    return 0; 
}