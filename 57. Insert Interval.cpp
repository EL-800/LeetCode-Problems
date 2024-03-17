#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> updatedIntervals;        
        int i;
        for (i = 0; i < intervals.size(); i++){
            auto interval = intervals[i];            
            if (interval[1] < newInterval[0])
                updatedIntervals.push_back(interval);
            else if (interval[0] > newInterval[1])
                break;
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]); 
            }
        }
        updatedIntervals.push_back(newInterval);
        for (i; i < intervals.size(); i++)
            updatedIntervals.push_back(intervals[i]);
        return updatedIntervals;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(){
    return 0;
}