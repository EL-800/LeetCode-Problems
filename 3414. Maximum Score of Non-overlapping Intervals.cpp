#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<pair<vector<int>, long long>>> memo;

    pair<vector<int>, long long> dp(vector<vector<int>>& intervals, int i = 0, int count = 4) {
        if(count == 0 || i == n) 
            return {{}, 0};

        if(memo[i][count].second != -1) 
            return memo[i][count];

        pair<vector<int>, long long> take;
        int j = n, left = i + 1, right = n - 1;        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(intervals[mid][0] > intervals[i][1]) {
                j = mid;
                right = mid-1;
            }
            else 
                left = mid+1;            
        }

        auto aux = dp(intervals, j, count - 1);
        take.first = aux.first;
        take.first.push_back(intervals[i][3]);

        sort(take.first.begin(), take.first.end());

        take.second = intervals[i][2] + aux.second;

        auto notTake = dp(intervals, i + 1, count);

        if(take.second > notTake.second) 
            return memo[i][count] = take;
        if(notTake.second > take.second) 
            return memo[i][count] = notTake;
        if(take.first < notTake.first) 
            return memo[i][count] = take;

        return memo[i][count] = notTake;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for(int i = 0; i < n; i++) 
            intervals[i].push_back(i);        
        sort(intervals.begin(), intervals.end());

        memo.assign(n, vector<pair<vector<int>, long long>>(5, {{}, -1}));
        auto ans = dp(intervals);

        return ans.first;
    }
};

int main() {
    return 0;
}